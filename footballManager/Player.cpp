#include "Player.h"

// Definição do construtor padrão
Player::Player()
    : name(""), position(""), age(0), number(0)
{
}

// Definição do construtor parametrizado
Player::Player(const string& name, const string& position, int age, int number)
{
    setPlayer(name, position, age, number);
}

// Definição do método para configurar os atributos da classe
void Player::setPlayer(const string& name, const string& position, int age, int number)
{
    // Verificações usando exceções
    if (age < 0)
    {
        throw invalid_argument("Age cannot be negative");
    }

    if (number < 0)
    {
        throw invalid_argument("Number cannot be negative");
    }

    if (name.empty())
    {
        throw invalid_argument("Name cannot be empty");
    }

    if (position.empty())
    {
        throw invalid_argument("Position cannot be empty");
    }

    // Atribui os valores aos membros
    this->name = name;
    this->position = position;
    this->age = age;
    this->number = number;
}

// Definição do destrutor
Player::~Player()
{
    // Não é necessário neste caso
}