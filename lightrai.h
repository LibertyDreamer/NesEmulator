#ifndef LIGHTRAI_H
#define LIGHTRAI_H

template<class C>
class LightRAI
{
    C* obj;
    LightRAI( const LightRAI& ) = delete;
    void operator=( const LightRAI& ) = delete;
public:
    LightRAI(C* obj){ this->obj = obj;}

    ~LightRAI(){ delete obj;}

    C* operator ->() { return obj;}
};

#endif // LIGHTRAI_H
