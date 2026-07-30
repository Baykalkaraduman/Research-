#ifndef PARTICLE_H
#define PARTICLE_H
#include <string>
#include <iostream>

#pragma once

class Particle {

//====================================================
// Attributes (Data Members)
//====================================================
private:
    int particle_id;
    std::string name;   
    double mass;            //GeV/c^2
    double charge;
    double momentum;        //GeV/c
    int detector_layer;
    bool alive;

    static int num_particle; // Buraya not al static kullanımı neden static int num{0} yasak
    // inline static int num_particle = 0; // Bu olur 

public:
//====================================================
// Methods (Member Functions) (Member Methods)
//====================================================

//----------------------------------------------------
//Inline Functions
//----------------------------------------------------

    //---------------------------
    // Getters
    //---------------------------
    int get_id() const {return particle_id;}
    std::string get_name() const {return name;} // Neden const koydum compiler tanısın diye.
    double get_mass() const {return mass;}
    double get_charge() const {return charge;}
    double get_momentum() const {return momentum;}
    int get_layer() const {return detector_layer;}
    bool get_alive() const {return alive;}
    
    //---------------------------
    // Setters
    //---------------------------
    void set_id(int id) {particle_id = id;}
    void set_name(std::string n) {name = n;}
    void set_mass(double m) {mass = m;}
    void set_charge(double c) {charge = c;}
    void set_momentum(double p) {momentum = p;}
    void set_detector_layer(int detlay) {detector_layer = detlay;}
    void set_alive(bool yn) {alive = yn;}

//----------------------------------------------------
// Constructors
//----------------------------------------------------

Particle (int particle_id = 0,    //Bunun nasıl yazıldığından bahset temel olarak fonksiyon prototype gibi aslında. Onlarda da default veriyi girebiliyordun bunda da.
        std::string name = "Unknown",
        double mass = 0.0,
        double charge = 0.0,
        double momentum = 0.0,
        int detector_layer = 0,
        bool alive = 1);

Particle (const Particle &source);

Particle (Particle &&source);

~Particle (); // main.cpp olmayan .cpp'deki tüm fonskiyonlar headerında tanımlanmalı.

    // Static Member Function
    static int get_num_particle(); // static class'a özel bir fonksiyon üstüne bir de private bir değişkene ulaşmaya çalışıyoruz daha kolay oluyor böyle.


//----------------------------------------------------
// Method (Member)Functions Decleration
//----------------------------------------------------

void display();



};
void display_particle(const Particle &particle);


#endif