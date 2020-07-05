#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;

class Ubranie{
private:
    string nazwa;
    string kolor;
    int rozmiar;
public:
    Ubranie(const string& n, const string& k, int r) :
        nazwa(n), kolor(k), rozmiar(r){
    }
    Ubranie() :
        Ubranie("", "", 0){
    }
    void set_nazwa(const string& n) {nazwa = n;}
    string get_nazwa()const {return nazwa;}
    void set_kolor(const string& k) {kolor = k;}
    string get_kolor()const {return kolor;}
    void set_rozmiar(int r) {rozmiar = r;}
    int get_rozmiar()const {return rozmiar;}
    virtual string opis()const = 0;
};

class Kurtka : public Ubranie{
private:
    int wodoodpornosc;
    int oddychalnosc;
public:
    Kurtka(const string& n, const string& k, int r, int w, int o) :
        Ubranie(n, k, r), wodoodpornosc(w), oddychalnosc(o){
    }
    Kurtka() :
        Ubranie(), wodoodpornosc(0), oddychalnosc(0){
    }
    void set_wodoodpornosc(int w) {wodoodpornosc = w;}
    int get_wodoodpornosc()const {return wodoodpornosc;}
    void set_oddychalnosc(int o) {oddychalnosc = o;}
    int get_oddychalnosc()const {return oddychalnosc;}
    virtual string opis()const{
        std::stringstream stream;
        stream.setf(std::ios_base::right, 
            std::ios_base::adjustfield);
        stream.width(10);
        stream << "Nazwa";
        stream.width(10);
        stream << "Kolor";
        stream.width(10);
        stream << "Rozmiar";
        stream.width(15);
        stream << "Oddychalnosc";
        stream.width(15);
        stream << "Wodoodpornosc" << std::endl;

        stream.width(10);
        stream << get_nazwa();
        stream.width(10);
        stream << get_kolor();
        stream.width(10);
        stream << get_rozmiar();
        stream.width(15);
        stream << oddychalnosc;
        stream.width(15);
        stream << wodoodpornosc;
        return stream.str();
    }
};

int main(){
    using std::cout;
    using std::endl;
    Ubranie* pt1 = new Kurtka("Lewis", "Czarny", 1, 2, 3);
    Ubranie* pt2 = new Kurtka("Lewis", "Czerwony", 1, 2, 3);
    Ubranie* pt3 = new Kurtka("Lewis", "Szary", 1, 2, 3);
    std::vector<Ubranie*> pointers({
        pt1, pt2, pt3
    });
    Kurtka* temp;
    int i = 0;
    for(auto& x : pointers){
        if(temp = dynamic_cast<Kurtka*>(x)){
            temp->set_wodoodpornosc(temp->get_wodoodpornosc() * ++i);
        }
        cout << x->opis() << endl;
        delete x;
    }
    return 0;
}