#include <iostream>
#include <vector>

using std::swap;
using std::vector;

// defining an enum for different point types.
enum PointType {OPEN, INVESTIGATE,CLOSE};
// defining an enum for different sort type, will use sort by the point's value, and sort by the point's type
enum SortType {VALUE,POINT_TYPE};

// defining a Point struct that stores the value of the point, the type of the point, and the initial index of the point (if it's the point to be investigated)
// initial_investigate_point_index will not be used for segment start point and segment end point.
// initial_investigate_point_index will be used for investigate_points because the initial point array is not sorted.

typedef struct {
  int value;
  PointType point_type;
  size_t initial_investigate_point_index;
} Point;



void merge(vector<Point> &combined_points, int left, int middle, int right, SortType sort_type) {

    int left_sub_array_size = middle - left + 1;
    int right_sub_array_size =  right - middle;

    /* create temp arrays */
    Point left_sub_array[left_sub_array_size], right_sub_array[right_sub_array_size];

    /* Copy data to temp arrays */
    for (size_t i = 0; i < left_sub_array_size; i++)
        left_sub_array[i] = combined_points[left + i];
    for (size_t j = 0; j < right_sub_array_size; j++)
        right_sub_array[j] = combined_points[middle + 1+ j];

    /* Merge the temp arrays back into combined_points[l..r]*/
    size_t i = 0; // Initial index of first subarray
    size_t j = 0; // Initial index of second subarray
    size_t k = left; // Initial index of merged subarray
    while (i < left_sub_array_size && j < right_sub_array_size)
    {
      if (sort_type==VALUE){
        //if need to sort by point value

        if (left_sub_array[i].value <= right_sub_array[j].value)
        {
            combined_points[k] = left_sub_array[i];
            i++;
        }
        else
        {
            combined_points[k] = right_sub_array[j];
            j++;
        }
        k++;

      } else if (sort_type==POINT_TYPE){
        //if need to sort by point type
        if (left_sub_array[i].point_type <= right_sub_array[j].point_type)
        {
            combined_points[k] = left_sub_array[i];
            i++;
        }
        else
        {
            combined_points[k] = right_sub_array[j];
            j++;
        }
        k++;
      }

    }

    /* Copy the remaining elements of left_sub_array[], if there
       are any */
    while (i < left_sub_array_size)
    {
        combined_points[k] = left_sub_array[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right_sub_array[], if there
       are any */
    while (j < right_sub_array_size)
    {
        combined_points[k] = right_sub_array[j];
        j++;
        k++;
    }
}


void mergeSort(vector<Point> &combined_points, int left, int right, SortType sort_type ) {
    if (left < right) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int middle = left+(right-left)/2;

        // Sort first and second halves
        mergeSort(combined_points, left, middle, sort_type);
        mergeSort(combined_points, middle+1, right, sort_type);
        merge(combined_points, left, middle, right, sort_type);
    }
}



vector<int> count_segments(vector<Point> combined_points, int point_size) {

  //sort the combined_points array by value (major criteria), and by point type (secondary criteria)
  //point type sequence = OPEN to the front of INVESTIGATE to the front of CLOSE
  mergeSort(combined_points, 0, combined_points.size()-1,POINT_TYPE);
  mergeSort(combined_points, 0, combined_points.size()-1,VALUE);

  //initiate the answer_vector of the same size as the initial investigate points.
  vector<int> answer_vector(point_size);

  //inititate the counter variable to store how many times each investigate point has been within a segment
  int counter = 0;
  //iterate through the combined (and sorted) points of starts, ends, and investigate point
  //because the combined_points array is an array of Point, and the Point struct has the attribute of PointType and value,
  //we are able to identify whether each iterated point in this for-loop as:
  //OPEN(start point of the segement), CLOSE(end point of the segement), or INVESTIGATE(initial investigate points)

  //to count how many segements each investigate point is in, we add 1 to the counter when we touch a OPEN point, we deduct 1 from the counter when we touch a CLOSE point,
  //once we hit the INVESTIGATE point, the counter value at the time is the answer for this investigate point.

  //EXAMPLE:
  // 2 3  -> segment 1
  // 0 5  -> segment 2
  // 7 10 -> segement 3
  // 1 6 11 -> investigate points
  // we combined all the points and sort => 0   1   2   3   5   6   7   10  11
  // O=open, C=close, I=investigate         O   I   O   C   C   I   O   C    I
  // meeting 0, open, counter++; counter is now 1
  // meeting 1, investigate, answer to point 1 is the current value of counter, which is 1;
  // meeting 2, open, counter++; counter is now 2
  // meeting 3, close, counter--; counter is now 1
  // meeting 5, close, countr--; counter is now 0
  // meeting 6, investigate, answer to point 6 is the current value of counter, which is 0;
  // meeting 7, open, counter++; counter is now 1
  // meeting 10, close, counter--; counter is now 0;
  // meeting 11, investigate, answer to point 11 is the current value of the counter, which is 0;

  // for this algorithm to work, if the Investigate point is the same as any start or end point of a segment, we need the INVESTIGATE point to be in the middle of segment open and segment close,
  // so that the +1 or -1 mechanism would work.
  size_t current_index;
  int temp_counter;
  for (size_t i = 0; i < combined_points.size(); i++){
    switch(combined_points[i].point_type) {
      case OPEN:
        counter++;
        break;
      case CLOSE:
        counter--;
        break;
      case INVESTIGATE:
        answer_vector[combined_points[i].initial_investigate_point_index] = counter;
        break;
      default:
        break;
    }
  }
  return answer_vector;
}



int main() {
  int segment_size, point_size;
  std::cin >> segment_size >> point_size;
  //initiate an array of Points to store the combined points of segment start, segment end, and investigate points

  vector<Point> combined_points(segment_size*2+point_size);
  int combined_points_index = 0;

  //put all the aforementioned points in the initiated array of combined_points
  for (size_t i = 0; i < segment_size; i++) {
    //value, point_type, index -> not gonna be used, don't initiate
    Point open_point = {0,OPEN};
    Point end_point = {0,CLOSE};
    std::cin >> open_point.value  >> end_point.value;
    combined_points[combined_points_index++] = open_point;
    combined_points[combined_points_index++] = end_point;
  }

  for (size_t i = 0; i < point_size; i++) {
    //value, point_type, index
    //the combined_point vector will be sorted so we will not know the initial INVESTIGATE point's sequence. by keeping the initial sequence
    //in the Point struct, we can refer back to the sequence when we need it.
    Point investigate_point = {0,INVESTIGATE,i};
    std::cin >> investigate_point.value;
    combined_points[combined_points_index++] = investigate_point;
  }

  vector<int> cnt = count_segments(combined_points, point_size);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
