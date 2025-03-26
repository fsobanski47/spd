#include <iostream>
#include <vector>

class Task {

    public: int r, p, q;
    public: Task(int r, int p, int q) {
        this->r = r;
        this->p = p;
        this->q = q;
    }
};

class Problem {
    std::vector<int> Cpi;
    std::vector<int> Cpiq;
    std::vector<Task> tasks;
    public: Problem() {
        tasks = {
                {1, 5, 9},
                {4, 5, 4},
                {1, 4, 6},
                {7, 3, 3},
                {3, 6, 8},
                {4, 7, 1}
        };
    }
    void calculateCpi() {
        Cpi.push_back(tasks[0].r + tasks[0].p);
        for(int j = 1; j < tasks.size(); j++) {
            Cpi.push_back(std::max(tasks[j].r, Cpi[j - 1]) + tasks[j].p);
        }
        for(int i : Cpi) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void calculateCpiq() {
        Cpiq.push_back(tasks[0].r + tasks[0].p + tasks[0].q);
        for(int j = 1; j < tasks.size(); j++) {
            Cpiq.push_back(std::max(tasks[j].r, Cpi[j - 1]) + tasks[j].p + tasks[j].q);
        }
        for(int i : Cpiq) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

class Result {

};

int main() {
    Problem problem;
    problem.calculateCpi();
    problem.calculateCpiq();

    return 0;
}
