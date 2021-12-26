/*
 * @Author: lei
 * @Description: 对Protobuf的Message类型的序列化和反序列化使用
 * @FilePath: /MyRpc/test/protobuf/protobuf_test.cc
 */
#include <iostream>
#include <string>
#include <vector>

#include "test.pb.h"
using namespace test;
using namespace std;
// complie: g++ -o protobuf_test protobuf_test.cc test.pb.cc -lprotobuf
// s为传出参数
void Test1(string& s) {
  People p1;
  p1.set_name("leiyx");
  p1.set_age(22);
  p1.set_height(170);
  p1.set_weight(60);
  p1.set_hobby(People_Hobby_SLEEP);
  // p1.set_hobby(People::SLEEP); 与上行等价
  p1.add_friends("you");
  p1.add_friends("ren");
  p1.add_friends("du");
  p1.add_friends("yang");
  Profession* pro = p1.mutable_job();
  pro->set_job_name("it");
  pro->set_salary(400000);
  s = p1.SerializeAsString();
  cout << "s.size()=" << s.size() << endl;
  cout << "s=" << s << endl;
  cout << "-------------- 序列化完成 ----------------" << endl;
}
void Test2(string& s) {
  People p2;
  p2.ParseFromString(s);
  cout << "name=" << p2.name() << endl;
  cout << "age=" << p2.age() << endl;
  cout << "height=" << p2.height() << endl;
  cout << "weight=" << p2.weight() << endl;
  cout << "hobby=" << p2.hobby() << endl;
  auto friends = p2.friends();
  for (auto& t : friends) {
    cout << t << " ";
  }
  cout << endl;
  test::Profession tmp = p2.job();
  cout << "job.job_name=" << tmp.job_name() << endl;
  cout << "job.salary=" << tmp.salary() << endl;
  cout << "--------------反序列化完成----------------" << endl;
}
int main() {
  string s;
  Test1(s);
  Test2(s);
  return 0;
}
// 存放相同的内容，json for modern c++序列化生成的string长度为142，
// 而protobuf序列化的长度为42，空间上来说，赢！
// 时间上来说，protobuf也赢！