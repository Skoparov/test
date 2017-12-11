#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "framework/world.h"
#include "components.h"

namespace game
{

ecs::entity& create_entity_map( const QRect& rect, ecs::world& world );
ecs::entity& create_entity_player_base( const QRect& rect, uint32_t health, ecs::world& world );
ecs::entity& create_entity_tile( const tile_type& type, const QRect& rect, ecs::world& world );
ecs::entity& create_entity_projectile( const QRect& rect,
                                       uint32_t damage,
                                       uint32_t speed,
                                       const movement_direction& direction,
                                       ecs::entity_id owner,
                                       ecs::world& world );

ecs::entity& create_entity_tank( const QRect& rect,
                                 const tank_type& type,
                                 uint32_t speed,
                                 uint32_t health,
                                 ecs::world& world );

QString tile_image_path( const tile_type& type );

}// game

#endif
