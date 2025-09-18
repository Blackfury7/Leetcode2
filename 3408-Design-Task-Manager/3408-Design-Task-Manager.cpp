class TaskManager {
public:
    map<pair<int,int>, int, greater<>> mapp;
    map<int,int>mapp2;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0; i<tasks.size(); i++){
            mapp[{tasks[i][2],tasks[i][1]}]=tasks[i][0];
            mapp2[tasks[i][1]]=tasks[i][2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mapp[{priority,taskId}]=userId;
        mapp2[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        int oldp=mapp2[taskId];
        int user=mapp[{oldp,taskId}];
        mapp.erase({oldp,taskId});
        mapp[{newPriority,taskId}]=user;
        mapp2[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        int pri=mapp2[taskId];
        mapp2.erase(taskId);
        mapp.erase({pri,taskId});
    }
    
    int execTop() {
        if (mapp.empty()) return -1;
        auto it = mapp.begin(); 
        int taskId = it->first.second;
        int user = it->second;
        rmv(taskId);            
        return user;
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