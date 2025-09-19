// 3408. Design Task Manager


class TaskManager {
public:
    using P = pair<int,int>;

    unordered_map<int,int> task_userId;
    unordered_map<int,int> task_priority;
    priority_queue<P, vector<P>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i=0; i<n; i++){
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];

            task_userId[taskId] = userId;
            task_priority[taskId] = priority;
            pq.push({priority,taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_userId[taskId] = userId;
        task_priority[taskId] = priority;
        pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        task_priority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        task_userId.erase(taskId);
        task_priority.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId] = pq.top();
            
            if (task_priority.count(taskId) && task_priority[taskId] == priority) {
                int userId = task_userId[taskId];
                task_userId.erase(taskId);
                task_priority.erase(taskId);
                pq.pop();
                return userId;
            }
            pq.pop();
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */