#include <iostream>
#include <string>
#include <fstream>

int pos = 0;

class Elf {
public:
	std::string name;

	int address = 0;
	std::string get_name() {
		return name;
	}

	int get_address() {
		return address;
	}
};

class MidBranch {
	int id = 0;
	int parent = 0;
	Elf elf;
public:

	int get_id() {
		return id;
	}

	int get_parent() {
		return parent;
	}

	Elf get_elf() {
		return elf;
	}

	void settlement(int elfs) {
		std::ifstream name("names.txt");
		std::string elfName;
		name.seekg(pos);
		std::getline(name, elfName);
		pos = name.tellg();
		if (elfName != "None") {
			elf.name = elfName;
			elf.address = id;
			++elfs;
			std::cout << elf.address << " | " << elf.name << " | Tree " << elf.address % 10 % 10 << ", Big branch " << (elf.address - (elf.address % 10 % 10)) / 10 % 10 << ", Middle branch " << elf.address / 100 << std::endl;
		}
	}

	MidBranch(int inId, int inParent, int elfs) {
		id = inId;
		parent = inParent;
		settlement(elfs);
	}
};

class BigBranch {
	int id = 0;
	int parent = 0;
	int daughter = 0;
	int elfs = 0;
	MidBranch** midBranch = nullptr;

public:
	int get_id() {
		return id;
	}

	int get_parent() {
		return parent;
	}

	int get_daughter() {
		return daughter;
	}

	int get_elfs() {
		return elfs;
	}

	MidBranch* get_midBranch(int index) {
		return midBranch[index];
	}

	BigBranch(int inId, int inParent, int inDaughter) {
		
		id = inId;
		parent = inParent;
		daughter = inDaughter;
		midBranch = new MidBranch * [daughter];
		
		for (int i = 0; i < daughter; ++i) {
			midBranch[i] = new MidBranch(((i + 1) * 100) + id, id, elfs);
		}
		
	}
};

class Tree {
	int id = 0;
	int parent = 0;
	int daughter = 0;
	BigBranch** bigBranch = nullptr;
	
public:
	
	int get_id() {
		return id;
	}

	int get_parent() {
		return parent;
	}

	int get_daughter() {
		return daughter;
	}

	BigBranch* get_bigBranch(int index) {
		return bigBranch[index];
	}

	Tree(int inId, int inParent, int inDaughter) {
		id = inId;
		parent = inParent;
		daughter = inDaughter;
		bigBranch = new BigBranch * [daughter];
		for (int i = 0; i < daughter; ++i) {
			bigBranch[i] = new BigBranch(((i+1)*10)+id, id, 3 - rand() % 1);
		}
	}

};

class Wood {
	Tree** tree = nullptr;

public:
	Tree* get_tree(int index) {
		return tree[index];
	}

	Wood() {
		tree = new Tree * [5];
		for (int i = 0; i < 5; ++i) {
			tree[i] = new Tree(i + 1, 0, 5 - rand() % 2);
		}
	}
};

int search(std::string name, Wood* wood) {
	int neighbours = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < wood->get_tree(i)->get_daughter(); ++j) {
			for (int x = 0; x < wood->get_tree(i)->get_bigBranch(j)->get_daughter(); ++x) {
				if (wood->get_tree(i)->get_bigBranch(j)->get_midBranch(x)->get_elf().name == name) {
					neighbours = wood->get_tree(i)->get_bigBranch(j)->get_elfs();
				}
			}
		}
	}
	return neighbours;
}

int main() {
	Wood* wood = new Wood;
	std::string name;
	std::cout << "Enter elf's name: ";
	std::cin >> name;
	std::cout << "Neighbours of " << name << ": " << search(name, wood) << std::endl;
}