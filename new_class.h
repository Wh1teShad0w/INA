#ifndef NEW_CLASS_H
#define NEW_CLASS_H

    #include <string>

    class new_class{
        public:
            new_class();//Constructeur
            new_class(std::string m_habit);//Constructeur en surcharge
                void manger(std::string nouriture);
            ~new_class();//Destructeur
    };

#endif // NEW_CLASS_H
