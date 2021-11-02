#include <iostream>
#include <string>

template <typename T>
struct Box
{
    T data;
    Box<T>* next;

    Box () { next = nullptr; }
    
    Box (const T& data)
    {
       this->data = data;
       next = nullptr; 
    }
};

template <typename T>
class LinkedList
{
private:
    Box<T>* first;

public:
    LinkedList() { first = nullptr; }

    ~LinkedList() 
    {
        Box<T>* ptr;
        while (first){
            ptr = first->next;
            delete first;
            first = ptr;
        }
    }

    void add (const T& newEl)
    {
        Box<T>* newElement = new Box<T>(newEl); 
        newElement->next = first;
        first = newElement;
    }

    void print()
    {
        Box<T>* curr = first;
        while (curr){
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    } 

    bool remove (const T& value)
    {
        Box<T>* curr = first;
        Box<T>* prev = nullptr;
        while (curr){
            if (curr->data == value){
                prev ? prev->next = curr->next : first = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    bool contains(const T& value)
    {
        Box<T>* curr = first;
        while (curr){
            if (curr->data == value){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    T sum ()
    {
        if (!first){
            return T();
        }
        T sum = first->data;
        Box<T>* curr = first->next;
        while (curr){
            sum += curr->data;
            curr = curr->next;
        }
        return sum;
    }

    LinkedList<T> reverse()
    {
        LinkedList<T> result;
        Box<T>* curr = first;
        while (curr){
            result.add(curr->data);
            curr = curr->next;
        }
        return result;
    }

    bool addOnPosition(const T& newEl, size_t pos)
    {
        if (pos == 0){
            this->add(newEl);
            return true;
        }
        Box<T>* curr = first;
        for (size_t i=0; i<pos-1; ++i){
            if (!curr) return false;
            curr = curr->next;
        }
        //we are on position pos-1
        if (!curr) return false;
        Box<T>* newElement = new Box<T>(newEl);
        newElement->next = curr->next;
        curr->next = newElement;
        return true;
    }
};

int main ()
{
    /*
    LinkedList<int> LL;
    std::cout << LL.sum() << "\n";
    LL.add(6);
    LL.add(8);
    LL.add(48);
    LL.remove(49);
    std::cout << LL.sum() << "\n";
    LL.print();
    */

    LinkedList<std::string> LLs;
    std::cout << LLs.sum() << "\n";
    LLs.add("radoslav");
    LLs.add("kaloyan");
    LLs.add("petar");
    //LLs.remove("petar");
    std::cout << LLs.sum() << "\n";
    LLs.print();
    std::cout << "---------------\n";
    //LLs.reverse().print();
    LLs.addOnPosition("elisaveta", 4);
    LLs.print();
    return 0;
}