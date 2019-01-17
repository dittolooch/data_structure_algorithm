#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

bool isLeft(char next){
  if (next == '(' || next == '[' || next == '{') {
    return true;
  } else {
    return false;
  }
}
bool isRight(char next){
  if (next == ')' || next == ']' || next == '}'){
    return true;
  } else {
    return false;
  }
}
int main() {
    std::string text;
    getline(std::cin, text);
    int failed_index = -1;
    std::stack<Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (isLeft(next)) {
            Bracket br(next, position);
            opening_brackets_stack.push(br);
        }

        if (isRight(next)){
            if (opening_brackets_stack.size() == 0){

              failed_index = position+1;
              break;
            } else {
              Bracket br(next, position);
              Bracket last = opening_brackets_stack.top();
              if (!last.Matchc(br.type)){

                failed_index = position+1;
                break;
              } else {
                opening_brackets_stack.pop();
              }

            }





        }
    }
    if (opening_brackets_stack.size()!=0){
      if (failed_index != -1){
        std::cout<<failed_index<<std::endl;
        // right mismtach
      } else {
        // left mismatch
        while(opening_brackets_stack.size()){
          failed_index = opening_brackets_stack.top().position+1;
          opening_brackets_stack.pop();
        }
        std::cout<<failed_index<<std::endl;
        //stack is not emptied, find the smallest index

      }
    } else if (failed_index != -1){
      std::cout<<failed_index<<std::endl;
    } else {
      std::cout<<"Success"<<std::endl;

    }
    // Printing answer, write your code here

    return 0;
}
