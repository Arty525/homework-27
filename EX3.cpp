#include <iostream>
#include <string>

class Staff {
public:

	std::string name;

};

class Worker : public Staff{
	int id;

public:

	int state = 0;
	enum status {
		A = 'A',
		B = 'B',
		C = 'C',
		FREE = 'FREE'
	};

	void set_status(int job) {
		state = job;
		state |= status(job);
	}

	Worker(int inId, int inJob) : Staff() {
		std::cout << "Enter worker's name: ";
		std::cin >> this->name;
		id = inId;
		state |= status(inJob);

		if (state < 3) {
			std::cout << name << " got a job:" << state << std::endl;
		}
		else {
			std::cout << name << " is free" << std::endl;
		}
	}
};

class Manager : public Staff {
	int id;
	int taskCount;
	int workers;
	int freeWorkers;
	int job;
	Worker** worker = nullptr;

public:

	Worker* get_worker(int j) {
		return worker[j];
	}

	int get_id() {
		return id;
	}

	int get_taskCount() {
		return taskCount;
	}

	void set_taskCount(int n) {
		taskCount = n;
	}

	void set_job() {
		if (taskCount > 0) {
			job = rand() % 2;
		}
		else job = 3;
	}

	int get_job() {
		return job;
	}
	
	void set_freeWorkers(int w) {
		freeWorkers = w;
	}

	int get_freeWorkers() {
		return freeWorkers;
	}

	Manager(std::string inName, int inX, int inId, int inWorkers) : Staff () {
		name = inName;
		id = inId;
		std::srand(inX + id);
		workers = inWorkers;
		freeWorkers = workers;
		taskCount = workers - rand() % workers - 1;

		if (taskCount == 0) taskCount = 1;

		std::cout << "Tasks: " << taskCount << std::endl;
		worker = new Worker * [workers];

		for (int i = 0; i < workers; ++i) {
			if (taskCount > 0) {
				job = rand() % 2;
			}
			else job = 3;
			worker[i] = new Worker(i + 1, job);
			if (worker[i]->state < 3) {
				--freeWorkers;
				--taskCount;
			}
			std::cout << "Free workers: " << freeWorkers << std::endl;
			std::cout << "Tasks amount: " << taskCount << std::endl;
		}
	}
};

class Team {
	int workers;
	int id;
	Manager* manager;

public:

	Manager* get_manager() {
		return manager;
	}
	int get_workers() {
		return workers;
	}
	int get_id() {
		return id;
	}

	Team(int inX, int inId) {
		std::string name;
		id = inId;
		std::cout << "Team " << inId << std::endl;
		std::cout << "Enter name of manager: ";
		std::cin >> name;
		std::cout << "Enter number of workers: ";
		std::cin >> workers;
		manager = new Manager(name, inX, inId, workers);
	}
};

class Director : public Staff {
	
	Team** team = nullptr;

public:

	Team* get_team(int i) {
		return team[i];
	}

	int x;

	Director(int inTeams) : Staff () {
		std::cout << "Enter seed number: ";
		std::cin >> x;
		std::cout << "Enter director's name: ";
		std::cin >> this->name;
		team = new Team * [inTeams];
		for (int i = 0; i < inTeams; ++i) {
			team[i] = new Team(x, i+1);
		}
	}
};

int main() {
	int teams = 0;
	std::string command;

	std::cout << "Enter number of teams: ";
	std::cin >> teams;

	Director director(teams);

	do {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "new task") {
			std::cout << "Enter seed number: ";
			std::cin >> director.x;
			for (int i = 0; i < teams; ++i) {
				if (director.get_team(i)->get_manager()->get_freeWorkers() == 0) {
					std::cout << "Team " << director.get_team(i)->get_id() << ": free workers is empty." << std::endl;
				}
				else {
					int n = 0;
					std::srand(director.get_team(i)->get_manager()->get_id() + director.x);
					n = director.get_team(i)->get_manager()->get_freeWorkers() - rand() % director.get_team(i)->get_manager()->get_freeWorkers() - 1;
					if (n == 0) n = 1;
					std::cout << "Free: " << director.get_team(i)->get_manager()->get_freeWorkers() << std::endl;
					std::cout << "Tasks: " << n << std::endl;
					director.get_team(i)->get_manager()->set_taskCount(n);
					for (int j = 0; j < director.get_team(i)->get_workers(); ++j) {
						if (director.get_team(i)->get_manager()->get_worker(j)->state == 3) {
							director.get_team(i)->get_manager()->set_job();
							director.get_team(i)->get_manager()->get_worker(j)->set_status(director.get_team(i)->get_manager()->get_job());
							std::cout << director.get_team(i)->get_manager()->get_worker(j)->name << " got a job: " << director.get_team(i)->get_manager()->get_worker(j)->state << std::endl;
							if (director.get_team(i)->get_manager()->get_worker(j)->state < 3) {
								director.get_team(i)->get_manager()->set_freeWorkers(director.get_team(i)->get_manager()->get_freeWorkers() - 1);
								director.get_team(i)->get_manager()->set_taskCount(director.get_team(i)->get_manager()->get_taskCount() - 1);
							}
						}
					}
				}
			}
		}
	} while (command != "stop");
	return 0;
}