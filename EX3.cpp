#include <iostream>
#include <string>
#include <vector>

class Staff {
public:
	std::string name;
};

class Worker : public Staff {
	int state = 0;
	enum status {
		A = 'A',
		B = 'B',
		C = 'C',
		FREE = 'FREE'
	};

public:

	void set_status(int job) {
		state = job;
		state |= status(job);
		if (state < 3) {
			std::cout << this->name << " got a job:" << status(state) << std::endl;
		}
		else {
			std::cout << this->name << " is free" << std::endl;
		}
	}

	int get_status() {
		return state;
	}

	Worker(int inJob) : Staff() {
		std::cout << "Enter worker's name: ";
		std::cin >> this->name;
		set_status(inJob);
	}
};

class Team {
	int workers = 0;
	int freeWorkers = 0;
	int tasks = 0;
	std::vector<Worker> staff;

public:

	int get_workers() {
		return workers;
	}

	int get_freeWorkers() {
		return freeWorkers;
	}

	int get_tasks() {
		return tasks;
	}

	Worker get_worker(int index) {
		return staff[index];
	}

	int newJob() {
		int job = 0;
		if (tasks > 0) {
			job = rand() % 2;
			--tasks;
			--freeWorkers;
		}
		else job = 3;
		return job;
	}

	void set_job(int inJob, int inId) {
		std::srand(inJob + inId);
		tasks = freeWorkers - rand() % freeWorkers;
		for (int i = 0; i < staff.size() && tasks > 0 && freeWorkers > 0; ++i) {
			std::cout << "Free: " << freeWorkers << std::endl;
			std::cout << "Tasks: " << tasks << std::endl;
			if (staff[i].get_status() != 3) {
				staff[i].set_status(newJob());
			}
		}
	}

	Team(int inJob, int inId) {
		std::cout << "Enter number of workers: ";
		std::cin >> workers;

		freeWorkers = workers;

		std::cout << "Free: " << freeWorkers << std::endl;

		if (freeWorkers > 0) {
			std::srand(inJob + inId);
			tasks = freeWorkers - rand() % freeWorkers;
			std::cout << "Tasks: " << tasks << std::endl;
		}
		else {
			std::cout << "Free workers is empty" << std::endl;
		}

		for (int i = 0; i < workers; ++i) {
			staff.push_back(Worker(newJob()));
			std::cout << "Free: " << freeWorkers << std::endl;
			std::cout << "Tasks: " << tasks << std::endl;
		}
	}
};

class Manager : public Staff {
	int id = 0;
	Team* team;

public:
	int get_id() {
		return id;
	}

	Team* get_team() {
		return team;
	}

	Manager(int inJob, int inId) : Staff() {
		id = inId;
		std::cout << "Manager Team #" << id << std::endl;
		std::cout << "Enter manager's name: ";
		std::cin >> this->name;
		team = new Team(inJob, inId);
	}
};

class Director : public Staff{
	int x = 0;
	Manager** manager = nullptr;

public:

	Manager* get_manager(int index) {
		return manager[index];
	}

	Director(int inTeams, int inX, std::string name) : Staff() {
		x = inX;		
		manager = new Manager * [inTeams];
		for (int i = 0; i < inTeams; ++i) {
			manager[i] = new Manager(x, i + 1);
		}
	}
};

int main() {
	std::string name;
	int teams = 0;
	int x = 0;
	std::cout << "Enter number of teams: ";
	std::cin >> teams;
	std::cout << "Enter seed number: ";
	std::cin >> x;
	std::cout << "Enter director's name: ";
	std::cin >> name;
	Director director = Director(teams, x, name);
	bool free = true;
	for (int i = 0; i < teams && free; ++i) {
		free = false;
		std::cout << "Team #" << i + 1<< std::endl;
		if (director.get_manager(i)->get_team()->get_freeWorkers() > 0) {
			free = true;
			int id = director.get_manager(i)->get_id();
			director.get_manager(i)->get_team()->set_job(x, id);
		}
		else {
			std::cout << "Free workers is empty." << std::endl;
		}
	}
	return 0;
}