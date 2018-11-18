#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};
int partition(vector<Segment> &data, int lo, int hi){
  int pivot = data[hi].end;
  Segment hi_segment = data[hi];
  int border_index = lo-1;
  for (int i=lo; i < hi; i++){
    if (data[i].end < pivot){
      border_index ++;
      Segment temp = data[i];
      data[i] = data[border_index];
      data[border_index] = temp;
    }
  }
  border_index ++;
  data[hi] = data[border_index];
  data[border_index] = hi_segment;
  return border_index;
}
void quicksort(vector<Segment> &data, int lo, int hi){
  if (hi-lo >= 1){
    int pivot_index = partition(data, lo, hi);
    quicksort(data, lo, pivot_index-1);
    quicksort(data,pivot_index+1, hi);
  }
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  quicksort(segments, 0, segments.size()-1);
  for (int i = 0; i < segments.size(); i++){
    if (i == 0){
      points.push_back(segments[i].end);
    } else {



      if (!(segments[i].start <= points.back() && segments[i].end >= points.back())){
        points.push_back(segments[i].end);
      }

    }

  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);


  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
