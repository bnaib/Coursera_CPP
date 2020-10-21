#include <string>
#include <map>

using namespace std;

class	TeamTasks {
	private:
		map<string, TasksInfo> m;
	public:
		const TasksInfo&				GetPersonTasksInfo(
			const string& person) const {
			return (this->m.at(person));
		}
		void							AddNewTask(
			const string& person) {
			this->m[person][TaskStatus::NEW]++;
		}
  		tuple<TasksInfo, TasksInfo>		PerformPersonTasks(
			const string& person, int task_count) {
			TasksInfo	update;
			TasksInfo	no_update;

			update[TaskStatus::IN_PROGRESS] =
				(task_count < this->m[person][TaskStatus::NEW]) ?
				task_count : this->m[person][TaskStatus::NEW];
			task_count -= update[TaskStatus::IN_PROGRESS];
			update[TaskStatus::TESTING] =
				(task_count < this->m[person][TaskStatus::IN_PROGRESS]) ?
				task_count : this->m[person][TaskStatus::IN_PROGRESS];
			task_count -= update[TaskStatus::TESTING];
			update[TaskStatus::DONE] =
				(task_count < this->m[person][TaskStatus::TESTING]) ?
				task_count : this->m[person][TaskStatus::TESTING];
			task_count -= update[TaskStatus::DONE];
			
			no_update[TaskStatus::TESTING] =
				this->m[person][TaskStatus::TESTING]
				- update[TaskStatus::DONE];
			no_update[TaskStatus::IN_PROGRESS] =
				this->m[person][TaskStatus::IN_PROGRESS]
				- update[TaskStatus::TESTING];
			no_update[TaskStatus::NEW] =
				this->m[person][TaskStatus::NEW]
				- update[TaskStatus::IN_PROGRESS];

			this->m[person][TaskStatus::NEW] -= update[TaskStatus::IN_PROGRESS];
			this->m[person][TaskStatus::IN_PROGRESS] +=
				update[TaskStatus::IN_PROGRESS]
				- update[TaskStatus::TESTING];
			this->m[person][TaskStatus::TESTING] +=
				update[TaskStatus::TESTING]
				- update[TaskStatus::DONE];
			this->m[person][TaskStatus::DONE] += update[TaskStatus::DONE];

			for (const auto& val : 
				{TaskStatus::NEW, TaskStatus::IN_PROGRESS,
				TaskStatus::TESTING, TaskStatus::DONE}
			) {
				if (update[val] == 0)
					update.erase(val);
				if (no_update[val] == 0)
					no_update.erase(val);
				if (this->m[person][val] == 0)
					this->m[person].erase(val);
			}

			return (make_tuple(update, no_update));
		}
};
