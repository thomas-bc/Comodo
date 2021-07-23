package comodo2.templates.qpc.impl;

import java.util.TreeSet;

import javax.inject.Inject;

import com.google.common.collect.Iterables;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.uml2.uml.StateMachine;
import org.eclipse.xtext.generator.IFileSystemAccess;
import org.eclipse.xtext.generator.IGenerator;
import org.eclipse.xtext.xbase.lib.IteratorExtensions;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;
import org.stringtemplate.v4.STGroupFile;

import comodo2.queries.QClass;
import comodo2.queries.QStateMachine;
import comodo2.templates.qpc.Utils;
import comodo2.templates.qpc.traceability.FileDescriptionHeader;
import comodo2.utils.FilesHelper;



public class QpcImplFiles implements IGenerator {


	@Inject
	private FilesHelper mFilesHelper;

	@Inject
	private QClass mQClass;

	@Inject
	private QStateMachine mQStateMachine;

	@Inject
	private Utils mUtils;

	@Inject
	private FileDescriptionHeader mFileDescHeader;

	// %1$s is impl_name      %2$s is funciton_name        "%%s" is escaping %s, which we want in the output
	final private String GUARD_FUNCTION_SOURCE_TEMPLATE = "" +
		"bool %1$s_impl_%2$s (%1$s_impl *mepl) {\n" +
		"	// bool rv = AttributeMapper_get(mepl, \"%2$s\");\n" +
		"	printf(\"%%s.%2$s() == %%d\", mepl->machineName, mepl->%2$s);\n" +
		"	return mepl->%2$s;\n" +
		"}\n";

	final private String ACTION_FUNCTION_SOURCE_TEMPLATE = "" +
		"void %1$s_impl_%2$s (%1$s_impl *mepl) {\n" +
		"	printf(\"%%s.%2$s() default action implementation invoked\\n\", mepl->machineName);\n" +
		"}\n";

    /**
	 * Process a UML State Machine associated to a class (classifier behavior)
	 * to generate implementation files associated to a State Machine file generated by QM.
	 * 
	 * The UML Class should:
	 * - be inside a UML Package with stereotype cmdoModule
	 * - the cmdoModule name should have been provided in the configuration
	 * - have stereotype cmdoComponent
	 * - have an associated UML State Machine
	 */
	@Override
	public void doGenerate(final Resource input, final IFileSystemAccess fsa) {


		Iterable<org.eclipse.uml2.uml.Class> _filter = Iterables.<org.eclipse.uml2.uml.Class>filter(IteratorExtensions.<EObject>toIterable(input.getAllContents()), org.eclipse.uml2.uml.Class.class);
		for (final org.eclipse.uml2.uml.Class e : _filter) {
			if ((mQClass.isToBeGenerated(e) && mQClass.hasStateMachines(e))) {
				for (final StateMachine sm : mQClass.getStateMachines(e)) {
					String className = e.getName();
					String smName = sm.getName();
					String smQualifiedName = className + "_" + smName;

					TreeSet<String> functionNames = mUtils.getAllActionFunctionNames(mQStateMachine.getAllActionNames(sm));
					TreeSet<String> guardNames = mQStateMachine.getAllGuardNames(sm);
					guardNames.remove("else"); // remove "else" guards which are not needed

					fsa.generateFile(mFilesHelper.toQmImplFilePath(smQualifiedName + "_impl.c"), this.generateImplSource(smQualifiedName, className, smName, functionNames, guardNames));						
					fsa.generateFile(mFilesHelper.toQmImplFilePath(smQualifiedName + "_impl.h"), this.generateImplHeader(smQualifiedName, className, smName, functionNames, guardNames));						
				}

			}
		}


	}

	/**
	 * Generates the source file for the implementation of actions and guards in the model
	 */
	public CharSequence generateImplSource(final String smQualifiedName, final String className, final String smName, final TreeSet<String> actionNames, final TreeSet<String> guardNames){
		STGroup g = new STGroupFile("resources/qpc_tpl/QpcImplFiles.stg");
		ST st = g.getInstanceOf("StateMachineImplSource");

		String methodsCodeString = "";
		TreeSet<String> guardNamesNoParenthesis = new TreeSet<String>();

		for (String guardName : guardNames) {
			methodsCodeString += printGuardFunction(smQualifiedName, guardName);
			guardNamesNoParenthesis.add(getFunctionName(guardName));
		}

		for (String actionName : actionNames) {
			methodsCodeString += printActionFunction(smQualifiedName, actionName);
		}

		st.add("fileDescriptionHeader", mFileDescHeader.generateFileDescriptionHeader(className, smName, false));
		st.add("className", className);
		st.add("smQualifiedName", smQualifiedName);
		st.add("guardNameList", guardNamesNoParenthesis);
		st.add("implementationMethodsCodeString", methodsCodeString);

		return st.render();
	}

	/**
	 * Generates the header file for the implementation of behaviors and guards in the model
	 */
	public CharSequence generateImplHeader(final String smQualifiedName, final String className, final String smName, final TreeSet<String> actionNames, final TreeSet<String> guardNames){
		STGroup g = new STGroupFile("resources/qpc_tpl/QpcImplFiles.stg");
		ST st = g.getInstanceOf("StateMachineImplHeader");
		
		TreeSet<String> guardNamesNoParenthesis = new TreeSet<String>();

		String methodsDefinition = "";
		
		for (String guardName : guardNames) {
			guardNamesNoParenthesis.add(getFunctionName(guardName));
			methodsDefinition += String.format("bool %s_impl_%s(" + smQualifiedName + "_impl *mepl);\n", smQualifiedName, getFunctionName(guardName));
		}
		
		for (String actionName : actionNames) {
			methodsDefinition += String.format("void %s_impl_%s(" + smQualifiedName + "_impl *mepl);\n", smQualifiedName, getFunctionName(actionName));
		}
		
		st.add("fileDescriptionHeader", mFileDescHeader.generateFileDescriptionHeader(className, smName, false));
		st.add("smQualifiedName", smQualifiedName);
		st.add("smQualifiedNameUpperCase", smQualifiedName.toUpperCase());
		st.add("guardNameList", guardNamesNoParenthesis);
		st.add("methodsDefinition", methodsDefinition);
		
		return st.render();
	}


	public CharSequence printGuardFunction(final String smQualifiedName, final String guardName){
		String str = "";
		str += String.format(GUARD_FUNCTION_SOURCE_TEMPLATE, smQualifiedName, getFunctionName(guardName));
		str += "\n";
		
		return str;
	}
	
	public CharSequence printActionFunction(final String smQualifiedName, final String actionName){
		String str = "";
		str += String.format(ACTION_FUNCTION_SOURCE_TEMPLATE, smQualifiedName, getFunctionName(actionName));
		str += "\n";

		return str;
	}

	public String getFunctionName(String str){
		//  This only takes what's before the first set of parentheses
		// Ok because we are passed a pre-processed list
		return str.trim().replaceAll("(?s)\\(.*\\).*","");
	}
}
