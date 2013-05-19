#include <CGAL/Cartesian.h>
#include <CGAL/Range_segment_tree_traits.h>
#include <CGAL/Range_tree_k.h>

typedef CGAL::Cartesian<double> K;
typedef CGAL::Range_segment_tree_set_traits_2<K> Traits;
typedef CGAL::Range_tree_2<Traits> Range_tree_2_type;

void query(int x1, double y1, int x2, double y2) {
  typedef Traits::Key Key;
  typedef Traits::Interval Interval;
  std::vector<Key> InputList, OutputList;
  std::vector<Key>::iterator first, last, current;

  InputList.push_back(Key(8,5.1));
  InputList.push_back(Key(1,1.1));
  InputList.push_back(Key(3,2.1));

  Range_tree_2_type Range_tree_2(InputList.begin(),InputList.end());

  Interval win=Interval(Key(x1,y1),Key(x2,y2));
  Range_tree_2.window_query(win, std::back_inserter(OutputList));
  current=OutputList.begin();
  while(current!=OutputList.end()){
    std::cout << (*current).x()<< "-" << (*current).y() << std::endl;
    current++;
  }
}

int main()
{
  std::cout << "Query:" << std::endl;
  query(4, 8.1, 5, 8.2);
  std::cout << "Query:" << std::endl;
  query(2, 1.2, 5, 8.2);
  std::cout << "Query:" << std::endl;
  query(0, 1.0, 9, 5.2);
}
