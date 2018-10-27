#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Schema {
public:
	Schema();
  void addAttribute(string a);
  int getIndexOf(string s);
	int size();
  string getAttributeAt(int i);
  string toString();
private:
	vector<string> schema;
  int numAttributes;
};
