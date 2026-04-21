#pragma once
#include <iostream>

class Jugador
{
private:
    std::string id;
    std::string nickname;
    std::string equipo;
    int nivel; // mayor a 0
    double puntuacion_previa;
    bool baneado;

public:
    Jugador(std::string nick, std::string equip, int niv, double punt)
        : nickname(nick), equipo(equip), nivel(0), puntuacion_previa(0)
    {
        setId(nick, equip);
        setNivel(niv);
        setPuntuacion(punt);
    }
    void setNivel(const int niv)
    {
        if (niv > 0)
        {
            nivel = niv;
            return;
        }
            nivel = 1;
            std::cout<<"El nivel tiene que ser mayor a 0"<<std::endl;
    }
    int getNivel(){ return nivel; }
    double getPuntuacion(){ return puntuacion_previa; }
    std::string getId(){ return id; }
    std::string getNickname(){ return nickname; }
    std::string getEquipo() { return equipo; }

    void setPuntuacion(double punt)
    {
        if (punt >= 5000)
        {
            std::cout<<"La puntuación tiene que ser menor o igual a 5000"<<std::endl;
            return;
        }
        puntuacion_previa = punt;
        comprobarBaneo();

    }

    void setId(std::string nick, std::string equip)
    {
        nickname = nick;
        equipo = equip;
        id = nick + "-" + equip;
    }

    void comprobarBaneo()
    {
        baneado = (puntuacion_previa < 0);
    }

};
