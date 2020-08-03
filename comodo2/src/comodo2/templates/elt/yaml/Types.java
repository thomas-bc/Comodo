package comodo2.templates.elt.yaml;

import org.eclipse.uml2.uml.Type;

public class Types {
	public String typeName(final Type t) {
		if (t.getName() != null) {
			switch (t.getName()) {
			case "Boolean":
				return "bool";
			case "String":
				return "std::string";
			case "Integer":
				return "int";
			case "Real":
				return "float";
			case "void":
				return "void";
			default:
				return t.getName();
			}
		} else {
			return t.getName();
		}
	}
}
