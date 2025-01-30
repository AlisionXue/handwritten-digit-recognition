#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Job {
public:
    Job(int id, int p, int l) : jobId(id), priority(p), length(l) {}

    int getLength() const { return length; }
    void decrementLength() { if (length > 0) length--; }
    int getPriority() const { return priority; }
    int getJobId() const { return jobId; }

    bool operator<(const Job& otherJob) const {
        return this->priority < otherJob.priority;
    }

private:
    int jobId;
    int length;
    int priority;
};

class Scheduler {
public:
    Scheduler() {}

    void addJob(const Job& j) {
        jobQueue.push(j);
    }

    void removeJob() {
        if (!jobQueue.empty()) {
            jobQueue.pop();
        }
    }

    Job getCurrentJob() {
        return jobQueue.top();
    }

    bool hasJobs() const {
        return !jobQueue.empty();
    }

    int getJobCount() const {
        return jobQueue.size();
    }

private:
    priority_queue<Job> jobQueue;
};

int main() {
    srand(time(0));
    Scheduler scheduler;

    for (int i = 0; i < 50; i++) {
        int priority = rand() % 40 - 19; 
        int length = rand() % 100 + 1; 
        scheduler.addJob(Job(i + 1, priority, length));
    }

    int cycle = 0;
    int totalJobsProcessed = 0;
    while (cycle < 2700) {
        if (scheduler.hasJobs()) {
            Job currentJob = scheduler.getCurrentJob();
            scheduler.removeJob();

            for (int i = 0; i < currentJob.getLength(); i++) {
                cycle++;
                if (cycle >= 2700) {
                    break;
                }
            }
            totalJobsProcessed++;
            cout << "Processed Job ID: " << currentJob.getJobId() << " with Priority: " << currentJob.getPriority() << "\n";
        }

        if (cycle % 20 == 0) {
            int newJobChance = rand() % 2; // 0 or 1
            if (newJobChance == 1) {
                int priority = rand() % 40 - 19; 
                int length = rand() % 100 + 1;   
                scheduler.addJob(Job(totalJobsProcessed + 51, priority, length));
                cout << "New Job Added with Priority: " << priority << " and Length: " << length << "\n";
            }
        }

        cycle++;
    }

    cout << "\nSimulation complete." << endl;
    cout << "Total jobs processed: " << totalJobsProcessed << endl;
    cout << "Jobs remaining in the queue: " << scheduler.getJobCount() << endl;

    return 0;
}
