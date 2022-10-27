#include <iostream>
#include <vector>
#include <string>

class Elf {
	std::string name;

public:

	std::string get_name() {
		return name;
	}

	Elf(std::string inName) {
		name = inName;
	}
};

class Branch {
	Branch* parent;
	int d = 0;
	Branch** big = nullptr;
	std::vector<Elf> elfs;

public:

	Branch* get_parent() {
		return parent;
	}

	Elf get_elfs(int i) {
		return elfs[i];
	}

	void set_elfs() {
		std::string name;
		for (int i = 0; i < 3; ++i) {
			std::cout << "Elf " << i << std::endl;
			std::cout << "Enter Elf's name: ";
			std::getline(std::cin, name);
				elfs.push_back(Elf(name));
		}
	}

	int search(std::string name) {
		int neighbours = 0;
		for (int i = 0; i < elfs.size(); ++i) {
			if (elfs[i].get_name() == name) {
				for (int j = 0; j < elfs.size(); ++j) {
					if (elfs[j].get_name() != "None" && elfs[j].get_name() != "none" && elfs[j].get_name() != name) {
						++neighbours;
					}
				}
			}
		}
		return neighbours;
	}

	Branch* get_big(int i) {
		return big[i];
	}

	int get_d() {
		return d;
	}

	Branch(int inD, Branch* inParent) {
		d = inD;
		parent = inParent;
		if (parent == nullptr) {
			big = new Branch * [d];
			for (int i = 0; i < d; ++i) {
				std::cout << "Big " << i << "; ";
				big[i] = new Branch(3 - rand() % 2, this);
			}
		}
		else {
			set_elfs();
		}
	}
};

int main() {
	std::string name;
	Branch** tree = nullptr;
	tree = new Branch * [5];
	for (int i = 0; i < 5; ++i) {
		std::cout << "Tree " << i << "; ";
		tree[i] = new Branch(5 - rand() % 3, nullptr);
	}

	std::cout << "Enter name for searching: ";
	std::getline(std::cin, name);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < tree[i]->get_d(); ++j) {
			for (int k = 0; k < tree[i]->get_big(j)->get_d(); ++k) {
				std::cout << "Neighbours: " << tree[i]->get_big(j)->search(name) << std::endl;
				break;
			}
		}
	}

	delete *tree;
	return 0;
}