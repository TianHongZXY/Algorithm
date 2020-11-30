#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> null_animal(2, -1);
class AnimalShelf {
public:
    queue<vector<int> > dogs;
    queue<vector<int> > cats;
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if(animal[1]) dogs.push(animal);
        else cats.push(animal);
    }
    
    vector<int> dequeueAny() {
        vector<int> res;
        if(!dogs.empty() && !cats.empty()){
            if(dogs.front()[0] < cats.front()[0]) res = dequeueDog();
            else res = dequeueCat();
        }
        else if(dogs.empty() && cats.empty()) return null_animal;
        else if(dogs.empty()) res = dequeueCat();
        else res = dequeueDog();
        return res;
    }
    
    vector<int> dequeueDog() {
        // cout << (dogs.empty() ? "dogs empty" : "dogs not empty") << endl;
        if(dogs.empty()) return null_animal;
        vector<int> res = dogs.front();
        dogs.pop();
        return res;
    }
    
    vector<int> dequeueCat() {
        // cout << (cats.empty() ? "cats empty" : "cats not empty") << endl;
        if(cats.empty()) return null_animal;
        vector<int> res = cats.front();
        cats.pop();
        return res;
    }
};


class AnimalShelf2 {
public:
    queue<vector<int> > animals;
    queue<vector<int> > cats_dogs[2];
    AnimalShelf2() {

    }
    
    void enqueue(vector<int> animal) {
        animals.push(animal);
    }
    
    vector<int> dequeueAny() {
        vector<int> res;
        // 二者要么全空，要么一空一非空，不可能都非空
        if(!cats_dogs[1].empty()) res = dequeueDog();
        else if(!cats_dogs[0].empty()) res = dequeueCat();
        else if(!animals.empty()){
            res = animals.front();
            animals.pop();
        }
        else return null_animal;
        return res;
    }
    
    vector<int> _dequeue(int cidx){
        if(!cats_dogs[cidx].empty()){
            vector<int> res = cats_dogs[cidx].front();
            cats_dogs[cidx].pop();
            return res;
        }
        while(!animals.empty() && animals.front()[1] != cidx){
            cats_dogs[!cidx].push(animals.front());
            animals.pop();
        }
        if(animals.size()){
            vector<int> res = animals.front();
            animals.pop();
            return res;
        }
        return null_animal;
    }

    vector<int> dequeueDog() {
        return _dequeue(1);
    }
    
    vector<int> dequeueCat() {
        return _dequeue(0);
    }
};

void print_vec(vector<int> vec){
    for(auto x : vec)
        cout << x << ' ';
    cout << endl;
}

int main(int argc, char const *argv[])
{
    AnimalShelf2* obj = new AnimalShelf2();
    vector<int> a; a.push_back(0); a.push_back(0);
    vector<int> b; b.push_back(1); b.push_back(0);
    // vector<int> c; c.push_back(2); c.push_back(1);
    obj->enqueue(a);
    obj->enqueue(b);
    // obj->enqueue(c);

    // vector<int> param_4 = obj->dequeueCat();
    vector<int> param_3 = obj->dequeueDog();
    vector<int> param_2 = obj->dequeueAny();
    // print_vec(param_4);
    print_vec(param_3);
    print_vec(param_2);

    return 0;
}
