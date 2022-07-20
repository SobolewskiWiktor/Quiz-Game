#ifndef know_classes
#define know_classes

#include <string>
#include <iostream>

using namespace std;
class Question
{
protected:
  string question;
  string good_answer;
  string answer_one;
  string answer_two;
  string answer_three;
  string answer_four;
  string question_number;
  string question_type;

public:
  Question(string Questions, string Good_answer, string Answer_one, string Answer_two, string Answer_three, string Answer_four, string Question_number, string Question_type)
  {
    question = Questions;
    good_answer = Good_answer;
    answer_one = Answer_one;
    answer_two = Answer_two;
    answer_three = Answer_three;
    answer_four = Answer_four;
    question_number = Question_number;
    question_type = Question_type;
  }
  // getters
  string get_question()
  {
    return question;
  }
  string get_good_answer()
  {
    return good_answer;
  }
  string get_answer_one()
  {
    return answer_one;
  }
  string get_answer_two()
  {
    return answer_two;
  }
  string get_answer_three()
  {
    return answer_three;
  }
  string get_answer_four()
  {
    return answer_four;
  }
  string get_question_number()
  {
    return question_number;
  }
  string get_quesion_type()
  {
    return question_type;
  }
  // setters
  void set_question(string Questions)
  {
    question = Questions;
  }
  void set_good_answer(string good)
  {
    good_answer = good;
  }
  void set_answer_two(string two)
  {
    answer_two = two;
  }
  void set_answer_three(string three)
  {
    answer_three = three;
  }
  void set_answer_four(string four)
  {
    answer_four = four;
  }
};
#endif
