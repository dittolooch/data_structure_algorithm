#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

typedef struct {
  size_t worker_index;
  long long finish_time;
} Node;

class PriorityQueue {
  vector<Node> nodes;
  int num_workers_;
public:
  void print_pq(){
    std::cout <<"printing queue" << std::endl;
    for (size_t i =0 ; i <nodes.size(); i++){
      std::cout <<"worker_index = "<< nodes[i].worker_index <<"finish_time = "<<nodes[i].finish_time<<std::endl;
    }
  }
  void initiate(int workers) {
    num_workers_ = workers;
    for (size_t i = 0 ; i < num_workers_; i++){
      Node worker;
      worker.worker_index = i;
      worker.finish_time = 0;
      nodes.push_back(worker);
    }
  }

  void bubble_down(int running){
    int left_child_index = running*2+1;
    int right_child_index = running*2+2;
    bool has_left_child = false;
    bool has_right_child = false;
    if (left_child_index < nodes.size()){
      has_left_child= true;
    }
    if (right_child_index < nodes.size()){
      has_right_child = true;
    }
    while (has_left_child || has_right_child){
      int smaller_child_index;
      bool swapped = false;
      //if have 2 children
      if (has_left_child && has_right_child){
        if (nodes[left_child_index].finish_time != nodes[right_child_index].finish_time){
          //if children finish time different
          if (nodes[left_child_index].finish_time < nodes[right_child_index].finish_time){
            //if left child finish earlier than right child
            smaller_child_index = left_child_index;
          } else {
            //if right child finish earlier than left child
            smaller_child_index = right_child_index;
          }
        } else {
          //if left child finish at same time as right child
          if (nodes[left_child_index].worker_index<nodes[right_child_index].worker_index){
            // if left child worker index smaller
            smaller_child_index = left_child_index;
          } else {
            smaller_child_index = right_child_index;
          }

        }
        //now we have the smaller child index
        if (nodes[smaller_child_index].finish_time != nodes[running].finish_time){
          // if smaller child finish time is not the same as running
          if (nodes[smaller_child_index].finish_time < nodes[running].finish_time){
            // if smaller child finish earlier
            swap(nodes[running], nodes[smaller_child_index]);
            swapped = true;
          } else {
            // if smaller child finish time bigger than running. no swap

          }
        } else {
          // if smaller child finish time is the same as running
            if (nodes[smaller_child_index].worker_index<nodes[running].worker_index){
              //check if smaller child worker index is smaller, then swap
              swap(nodes[running], nodes[smaller_child_index]);
              swapped = true;
            }
        }


      } else if (has_left_child) {
        // no two child , only one child
        smaller_child_index = left_child_index;

        if (nodes[smaller_child_index].finish_time != nodes[running].finish_time){
          // if smaller child finish time is not the same as running
          if (nodes[smaller_child_index].finish_time < nodes[running].finish_time){
            // if smaller child finish earlier
            swap(nodes[running], nodes[smaller_child_index]);
            swapped = true;
          } else {
            // if smaller child finish time bigger than running. no swap

          }
        } else {
          // if smaller child finish time is the same as running

            if (nodes[smaller_child_index].worker_index<nodes[running].worker_index){
              //check if smaller child worker index is smaller, then swap
              swap(nodes[running], nodes[smaller_child_index]);
              swapped = true;
            }
        }
      }
      if (swapped){
        running = smaller_child_index;
        left_child_index = running*2+1;
        right_child_index = running*2+2;
        has_left_child = left_child_index < nodes.size();
        has_right_child = right_child_index < nodes.size();
      } else {
        return;
      }
    }
  }

public:
  Node get_root(){
    return nodes[0];
  }
  bool is_empty(){
    if (nodes.size()==0){
      return true;
    } else {
      return false;
    }
  }
  void assign_new_root_finish_time(long long new_finish_time){
    nodes[0].finish_time = new_finish_time;
    bubble_down(0);
  }

};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  PriorityQueue queue;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }
  void InitPriorityQueue() {
    queue.initiate(num_workers_);

  }
  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // queue.print_pq();
    for (size_t i = 0; i < jobs_.size(); i++){
      Node root = queue.get_root();
      int worker_index = root.worker_index;
      long long start_time= root.finish_time;
      long long finish_time = start_time + jobs_[i];
      assigned_workers_.push_back(worker_index);
      start_times_.push_back(start_time);
      // std::cout<<jobs_[i] <<"-task assigned to "<<worker_index<<" start_time = " <<start_time <<" end time "<<finish_time<<std::endl;
      queue.assign_new_root_finish_time(finish_time);
      // queue.print_pq();
    }

  }

 public:
  void Solve() {
    ReadData();
    InitPriorityQueue();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
