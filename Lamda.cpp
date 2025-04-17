#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>


using namespace std;


struct Person {
    std::string name;
    int age;
};

bool compartor(const Person&a, const Person&b)
{
    return a.age < b.age;
}

int main()
{
    std::vector<Person> people = {
        {"Alice", 25},
        {"Bob", 20},
        {"Charlie", 40},
        {"Omar", 34}
    };


    cout<<"list people before sorting: "<<endl;
    for(auto itr = people.begin(); itr != people.end(); itr++)
    {
        cout<<itr->name<<" "<<itr->age<<endl;
    }

    /* sort the people according to age */
    sort(people.begin(), people.end(), compartor);

    cout<<"list people after sorting by age: "<<endl;
    for(auto itr = people.begin(); itr != people.end(); itr++)
    {
        cout<<itr->name<<" "<<itr->age<<endl;
    }

    /* use find_if to find if name exists */
    string name = "Alice";

    auto itr = find_if(people.begin(), people.end(), [name](const Person&a)
                                                    {
                                                        return a.name == name; 
                                                    });

    if(itr != people.end()) cout<<"Found: "<< itr->name<< " " <<itr->age<<endl;
    else cout<<"Person not found"<<endl;

    /* use lower bound to find first person with certain age or not less than given age */
    int age = 30;

    auto itr2 = lower_bound(people.begin(), people.end(), age, [](const Person&a, int age)
                                                                {
                                                                    return a.age < age; 
                                                                });


    if(itr2 != people.end()) cout<<"Found: "<< itr2->name<< " " <<itr2->age<<endl;
    else cout<<"Person not found"<<endl;

    /* add 5 to each person's age using for_each */
    for_each(people.begin(), people.end(), [](Person &p)
                                            {
                                                p.age += 5;
                                            });


    cout<<"list people after adding 5 to their age: "<<endl;
    for(auto const& e : people)
    {
        cout<<e.name<<" "<<e.age<<endl;
    }

    int totalAge = accumulate(people.begin(), people.end(), 0, [](int sum, const Person&p){
                                                                    return sum + p.age;
                                                                });

    cout<<"Total age: " <<totalAge<<endl;

    return 0;
}