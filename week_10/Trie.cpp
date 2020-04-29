/*
Алгоритм Ахо-Корасик
Пусть дан набор строк в алфавите размера k суммарной длины m. 
Алгоритм Ахо-Корасик строит для этого набора строк структуру данных "бор", а затем по этому бору строит автомат, 
всё за O(m) времени и O (m*k) памяти. 
*/

#include <iostream>
#include <map>

using namespace std;

struct vertex{
    map<char, vertex*> next;
    bool leaf;
    string prefix;

    vertex(string _prefix){
        prefix = _prefix;
    }
};

class Trie{

    private:
        vertex* root;

        void printNodeInfo(vertex* node){
            map<char, vertex*> :: iterator it;

            for(it = node->next.begin(); it != node->next.end(); ++it){
                string end = it -> second -> leaf == false ? "No" : "Yes";
                cout << "A vertex is: "<< it -> second -> prefix << ". " << "Is it end? " << end << ". ";
            }
            cout << endl;
        }
    
    public:
        Trie(){
            root = new vertex("/");
        }
        vertex* getRoot(){
            return root;
        }

        /* addString(string s) method adds to trie parameter of string */
        void addString(string s){
            vertex* current = root;

            for(size_t i=0; i < s.size(); ++i){
                if(current->next.find(s[i]) == current->next.end()){
                    current -> next[s[i]] = new vertex(current->prefix + s[i]);
                }
                current = current->next[s[i]];
            }
            current->leaf = true;
        }

        /* find(string s) method is to determine is the string in the trie */
        bool find(string s){

            bool result = true;
            vertex* current = root;

            for(size_t i=0; i < s.size(); ++i){//At initial position we determine is char of string in the trie, if not we add it to trie.
                if(current->next.find(s[i]) == current->next.end()){
                    result = false;
                    break;
                }
                current = current -> next[s[i]];
            }
            return result && current->leaf;
        }
        /* print(vertex* node) method prints the info about the trie */
        void print(vertex* node){
            map<char, vertex*> :: iterator it;
            printNodeInfo(node);

            for(it = node -> next.begin(); it != node -> next.end(); ++it){
                print(it -> second);
            }
        } 
};

int main(){

    Trie t;

    string arr[] = {"John", "Tom", "Alice", "Tim", "Anne"};

    int n = sizeof(arr)/sizeof(string);

    for(size_t i=0; i < n; ++i)
        t.addString(arr[i]);
    
    printf("%d\t\n", t.find("Alice"));

    t.print(t.getRoot());
 
    return 0;
}