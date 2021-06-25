package comodo2.templates.qpc;

import comodo2.engine.Main;
import comodo2.queries.QClass;
import javax.inject.Inject;
import org.apache.log4j.Logger;
import org.eclipse.emf.common.util.TreeIterator;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.uml2.uml.StateMachine;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.generator.IFileSystemAccess;
import org.eclipse.xtext.generator.IGenerator;

public class Qpc implements IGenerator {

	private static final Logger mLogger = Logger.getLogger(Main.class);

	@Inject
	private QClass mQClass;

	/**
	 * Transform UML State Machine associated to a class (classifier behavior)
	 * into an QPC model.
	 * 
	 * The UML Class should:
	 * - be inside a UML Package with stereotype cmdoModule
	 * - the cmdoModule name should have been provided in the configuration
	 * - have stereotype cmdoComponent
	 * - have an associated UML State Machine
	 */
	@Override
	public void doGenerate(final Resource input, final IFileSystemAccess fsa) {
		final TreeIterator<EObject> allContents = input.getAllContents();
		while (allContents.hasNext()) {
			EObject e = allContents.next();
			if (e instanceof org.eclipse.uml2.uml.Class) {
				org.eclipse.uml2.uml.Class c = (org.eclipse.uml2.uml.Class)e; 
				if ((mQClass.isToBeGenerated(c) && mQClass.hasStateMachines(c))) {
					for (final StateMachine sm : mQClass.getStateMachines(c)) {
						fsa.generateFile(sm.getName()+".xml", this.generate(sm));
					}
				}				
			}
		}
	}

	public CharSequence generate(final StateMachine sm) {
		mLogger.debug("Generating QPC code for " + sm.getName() + " state machine.");
		StringConcatenation str = new StringConcatenation();
		str.append("QPC code here");
		str.newLineIfNotEmpty();
		return str;
	}

}
