#include "tables.h"

NodeTable::NodeTable() {
	name = "";
	element = NULL;
}

NodeTable::NodeTable(const NodeTable& t) {
	name = t.GetKey();
	element =t.GetElement(); //new PList(*t.GetElement());
}

NodeTable::NodeTable(string name_, PList* elem) {
	name = name_;
	element = elem;
}

NodeTable& NodeTable::operator=(NodeTable& t) {
	if (this == &t) {
		return *this;
	}
	name = t.GetKey();
	element = t.GetElement();
	return *this;
}

bool NodeTable::operator==(const NodeTable& t)
{
	return t.GetKey() == GetKey();
}

string NodeTable::GetKey() const{
	return name;
}
PList* NodeTable::GetElement() const{
	return element;
}
