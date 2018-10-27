#include "relation.h"

Relation::Relation() { numRows = 0; }

void Relation::addColumns(Schema s) {
  columns = s;
}

void Relation::addRow(Tuple t) {
  rows.insert(t);
  numRows++;
}

Relation Relation::selectColumnValue(string column, string value) {
  Relation newTable;
  Schema newHeader;
  newTable.addColumns(this->columns);
  int columnIndex = this->columns.getIndexOf(column);

  for (set<Tuple>::iterator it = rows.begin(); it != rows.end(); ++it) {
    if (it->at(columnIndex) == value) {
      newTable.addRow(*it);
    }
  }

  return newTable;
}

Relation Relation::selectColumnColumn(string column1, string column2) {
  Relation newTable;
  newTable.addColumns(this->columns);
  int columnIndex1 = this->columns.getIndexOf(column1);
  int columnIndex2 = this->columns.getIndexOf(column2);

  for (set<Tuple>::iterator it = rows.begin(); it != rows.end(); ++it) {
      if (it->at(columnIndex1) == it->at(columnIndex2)) {
        newTable.addRow(*it);
      }
  }

  return newTable;
}

Schema Relation::getColumns() {
  return columns;
}

set<Tuple> Relation::getRows() {
  return rows;
}

string Relation::printColumns() {
    std::stringstream ss;
    ss << columns.toString();
    return ss.str();
}

string Relation::printRows() {
  std::stringstream ss;
  int numColumns = columns.size();

  for (set<Tuple>::iterator it = this->rows.begin(); it != this->rows.end(); ++it) {
      for (int i = 0; i < numColumns; i++) {
        ss << it->at(i) << ",\t";
      }
      ss << "\n";
  }

  return ss.str();
}
