#include "Tile.h"

Tile::Tile(TypeCase type) : m_typeCase(type)
{

}

TypeCase Tile::getTypeCase()
{
    return m_typeCase;
}

Ressource Tile::getRessource()
{
    return m_ressource;
}