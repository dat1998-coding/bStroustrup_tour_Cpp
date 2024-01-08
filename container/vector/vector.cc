#include<iostream>
#include<limits>
#include<vector>
// just push ele in vector, see limits for right input
void ex_vector_1() {
    unsigned long int phoneNr(0);
    std::vector<unsigned long int> phoneNr_List;
    std::cout<<"Input number\n";
    unsigned long limit = std::numeric_limits<unsigned long int>::max();
    for(phoneNr; std::cin>>phoneNr; ) {
        if ((phoneNr/100000) <= 0 || phoneNr > limit) {// limit, catch .. throw for exception and robustness
            std::cout<<"(test) Invalid phone number, digits should be more than 6 and cannot pass "<< limit <<" \n";
            continue;
        }
        phoneNr_List.push_back(phoneNr);
        std::cout<<"Nr of phone number in the list:"<<phoneNr_List.size()<<"\n";
        if (phoneNr_List.size() > 9) break;
    }
}
// test addr vector after reserve
// The way it reserve is allocate double amount if reach old cap
void ex_vector_2() {
    std::vector<int> m_vec;
    std::cout<<"Vector's size before reserving: " << m_vec.size() << "\n";
    std::cout<<"First element addr " << &m_vec[0] <<"\n";
    int reserve_size = 4;
    std::cout << "Reserve size: "<< reserve_size << "\n";
    m_vec.reserve(reserve_size);
    std::cout<<"Capacity after reserve_1: " << m_vec.capacity()<<"\n";
    std::cout<<"Vector's size after reserving_1: " << m_vec.size() << "\n";
    std::cout<<"First element addr " << &m_vec[0] <<"\n";
    std::cout<<"Push back "<< reserve_size <<" elements to vector\n";
    int input = 0;
    for(int i = 0; i < reserve_size; i++) {
        std::cin>>input;
        m_vec.push_back(input);
    }
    reserve_size = 100;
    std::cout<<"Reserve more for vector, size: " << reserve_size <<"\n";
    m_vec.reserve(reserve_size);
    std::cout<<"Vector's size after reserving_2: " << m_vec.size() << "\n";
    std::cout<<"Capacity after reserve_2: " << m_vec.capacity()<<"\n";
    std::cout<<"First element addr " << &m_vec[0] <<"\n";
    std::cout<<"Print:\n";
    for(const auto& x: m_vec) {
        std::cout<< x <<"\t";
    }
    std::cout<<"\n";
    std::cout<<"floading vector more elements than capacity - test 2 times\n";
    int idx = 0;
    int dummy_val = 1;
    do {
        int old_cap = m_vec.capacity();
        for (int i = 0; i < old_cap + 1; i++) {
            m_vec.push_back(dummy_val);
        }
        std::cout<<"Vector's size after floading_" << idx << ": " << m_vec.size() << "\n";
        std::cout<<"Capacity after floading: " << m_vec.capacity()<<"\n";
        idx++;
    } while (idx!= 2);
}
// vector.at() to try catch 
void ex_vector_3() {
    std::vector<int> vec = {1, 2, 3, 4};
    std::cout<< "We got vector size: "<< vec.size() <<" cap: "<<vec.capacity() << "\n";
    
    /*ex here will not return err
    ramdom value is shown instead -> undesired*/
    std::cout<< "Last element: " << vec[vec.size()]<< " (undesired)"<<"\n";
    
    // use at() to throw err
    try {
        std::cout<< "Last element: " << vec.at(vec.size())<<"\n";
    }
    catch (const std::out_of_range& oor){
        std::cerr<< "Access invalid memory " << oor.what() << "\n";
    }
}
int main() {
    ex_vector_3();
    return 0;
}