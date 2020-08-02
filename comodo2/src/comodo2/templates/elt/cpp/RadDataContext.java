package comodo2.templates.elt.cpp;

import com.google.common.collect.Iterables;
import comodo2.engine.Config;
import comodo2.queries.QClass;
import comodo2.utils.FilesHelper;
import javax.inject.Inject;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.generator.IFileSystemAccess;
import org.eclipse.xtext.generator.IGenerator;
import org.eclipse.xtext.xbase.lib.Extension;
import org.eclipse.xtext.xbase.lib.IteratorExtensions;

@SuppressWarnings("all")
public class RadDataContext implements IGenerator {
  @Inject
  @Extension
  private QClass _qClass;
  
  @Inject
  @Extension
  private FilesHelper _filesHelper;
  
  /**
   * Transform UML State Machine associated to a class (classifier behavior)
   * into a RAD ActionMgr class.
   */
  @Override
  public void doGenerate(final Resource input, final IFileSystemAccess fsa) {
    Iterable<org.eclipse.uml2.uml.Class> _filter = Iterables.<org.eclipse.uml2.uml.Class>filter(IteratorExtensions.<EObject>toIterable(input.getAllContents()), org.eclipse.uml2.uml.Class.class);
    for (final org.eclipse.uml2.uml.Class e : _filter) {
      boolean _isToBeGenerated = this._qClass.isToBeGenerated(e);
      if (_isToBeGenerated) {
        this._filesHelper.makeBackup(this._filesHelper.toAbsolutePath(this._filesHelper.toHppFilePath("dataContext")));
        fsa.generateFile(this._filesHelper.toHppFilePath("dataContext"), this.generateHeader(Config.getInstance().getCurrentModule(), "DataContext"));
        this._filesHelper.makeBackup(this._filesHelper.toAbsolutePath(this._filesHelper.toCppFilePath("dataContext")));
        fsa.generateFile(this._filesHelper.toCppFilePath("dataContext"), this.generateSource(Config.getInstance().getCurrentModule(), "DataContext"));
      }
    }
  }
  
  /**
   * dataContext.hpp
   */
  public CharSequence generateHeader(final String moduleName, final String className) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("/**");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @file");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @ingroup ");
    _builder.append(moduleName, " ");
    _builder.newLineIfNotEmpty();
    _builder.append(" ");
    _builder.append("* @copyright ESO - European Southern Observatory");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @author");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("*");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @brief ");
    _builder.append(className, " ");
    _builder.append(" header file.");
    _builder.newLineIfNotEmpty();
    _builder.append(" ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("#ifndef ");
    String _upperCase = moduleName.toUpperCase();
    _builder.append(_upperCase);
    _builder.append("_");
    String _upperCase_1 = className.toUpperCase();
    _builder.append(_upperCase_1);
    _builder.append("_HPP_");
    _builder.newLineIfNotEmpty();
    _builder.append("#define ");
    String _upperCase_2 = moduleName.toUpperCase();
    _builder.append(_upperCase_2);
    _builder.append("_");
    String _upperCase_3 = className.toUpperCase();
    _builder.append(_upperCase_3);
    _builder.append("_HPP_");
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("#include <");
    _builder.append(moduleName);
    _builder.append("/config.hpp>");
    _builder.newLineIfNotEmpty();
    _builder.append("#include <");
    _builder.append(moduleName);
    _builder.append("/dbInterface.hpp>");
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("namespace ");
    String _lowerCase = moduleName.toLowerCase();
    _builder.append(_lowerCase);
    _builder.append(" {");
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("/**");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* This class provide access to the application run-time data including");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* the in-memory DB.");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("class DataContext {");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("public:");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("/**");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* This constructor uses the application configuration to initialize the");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* adapter object to the in-memory DB.");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* The DB adapter is then used to initialize the DB interface object that");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* can be used to access the DB key-value pairs.");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("*");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* @param[in] config Reference to the application configuration.");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("*/");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("DataContext(Config& config, rad::DbAdapter& db_adapter);");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("/**");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* Destructor");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("virtual ~DataContext();");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("/**");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* Reload the configuration from file and reconnect to the in-memory DB.");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("void ReloadConfig();");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("/**");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* Try to connect to the DB and update the application configuration.");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("void UpdateDb();");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("/**");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("* @return A reference to the DB interface object.");
    _builder.newLine();
    _builder.append("     ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("DbInterface& GetDbInterface();");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("DataContext(const DataContext&) = delete;       //! Disable copy constructor");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("DataContext& operator=(const DataContext&) = delete;  //! Disable assignment operator");
    _builder.newLine();
    _builder.newLine();
    _builder.append(" ");
    _builder.append("private:");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("Config&            m_config;");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("rad::DbAdapter&    m_runtime_db;");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("DbInterface        m_db_interface;");
    _builder.newLine();
    _builder.append("};");
    _builder.newLine();
    _builder.newLine();
    _builder.append("}  // namespace ");
    String _lowerCase_1 = moduleName.toLowerCase();
    _builder.append(_lowerCase_1);
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("#endif  // ");
    String _upperCase_4 = moduleName.toUpperCase();
    _builder.append(_upperCase_4);
    _builder.append("_");
    String _upperCase_5 = className.toUpperCase();
    _builder.append(_upperCase_5);
    _builder.append("_HPP_");
    _builder.newLineIfNotEmpty();
    return _builder;
  }
  
  /**
   * dataContext.cpp
   */
  public CharSequence generateSource(final String moduleName, final String className) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("/**");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @file");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @ingroup ");
    _builder.append(moduleName, " ");
    _builder.newLineIfNotEmpty();
    _builder.append(" ");
    _builder.append("* @copyright ESO - European Southern Observatory");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @author");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("*");
    _builder.newLine();
    _builder.append(" ");
    _builder.append("* @brief ");
    _builder.append(className, " ");
    _builder.append(" source file.");
    _builder.newLineIfNotEmpty();
    _builder.append(" ");
    _builder.append("*/");
    _builder.newLine();
    _builder.newLine();
    _builder.append("#include <");
    _builder.append(moduleName);
    _builder.append("/dataContext.hpp>");
    _builder.newLineIfNotEmpty();
    _builder.append("#include <");
    _builder.append(moduleName);
    _builder.append("/logger.hpp>");
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("#include <rad/assert.hpp>");
    _builder.newLine();
    _builder.append("#include <rad/exceptions.hpp>");
    _builder.newLine();
    _builder.newLine();
    _builder.append("namespace ");
    String _lowerCase = moduleName.toLowerCase();
    _builder.append(_lowerCase);
    _builder.append(" {");
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("DataContext::DataContext(Config& config, rad::DbAdapter& db_adapter)");
    _builder.newLine();
    _builder.append(": m_config(config),");
    _builder.newLine();
    _builder.append("  ");
    _builder.append("m_runtime_db(db_adapter),");
    _builder.newLine();
    _builder.append("  ");
    _builder.append("m_db_interface(m_config.GetProcName(), m_runtime_db) {");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("RAD_TRACE(GetLogger());");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("UpdateDb();");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    _builder.append("DataContext::~DataContext() {");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("RAD_TRACE(GetLogger());");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    _builder.append("void DataContext::ReloadConfig() {");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("RAD_TRACE(GetLogger());");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("m_config.LoadConfig(m_config.GetConfigFilename());");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("UpdateDb();");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    _builder.append("void DataContext::UpdateDb() {");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("RAD_TRACE(GetLogger());");
    _builder.newLine();
    _builder.newLine();
    _builder.append("    ");
    _builder.append("try {");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("m_runtime_db.Disconnect();");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("m_runtime_db.Config(m_config.GetDbEndpoint(), m_config.GetDbTimeout());");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("m_runtime_db.Connect();");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("RAD_ASSERT(m_runtime_db.IsConnected());");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("m_db_interface.SetConfig(m_config);");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("} catch (rad::RuntimeDbException& e) {");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("/*");
    _builder.newLine();
    _builder.append("         ");
    _builder.append("* Log error but do not terminate, DB could be temporarily unavailable.");
    _builder.newLine();
    _builder.append("         ");
    _builder.append("*/");
    _builder.newLine();
    _builder.append("        ");
    _builder.append("LOG4CPLUS_ERROR(GetLogger(), e.what());");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("}");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    _builder.append("DbInterface& DataContext::GetDbInterface() {");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("RAD_TRACE(GetLogger());");
    _builder.newLine();
    _builder.append("    ");
    _builder.append("return m_db_interface;");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    _builder.append("}  // namespace ");
    String _lowerCase_1 = moduleName.toLowerCase();
    _builder.append(_lowerCase_1);
    _builder.newLineIfNotEmpty();
    return _builder;
  }
}
