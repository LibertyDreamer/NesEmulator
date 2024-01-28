#ifndef LIGHT_RAI_H
#define LIGHT_RAI_H

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

#endif // LIGHT_RAI_H
