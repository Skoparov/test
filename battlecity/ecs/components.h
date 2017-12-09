#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <QRect>
#include <QString>

namespace game
{

enum class tile_type{ wall, empty };
enum class tank_type{ player, enemy };

namespace component
{

class tile_object final
{
public:
    tile_object() = default;
    tile_object( const tile_type& type ) noexcept;

    void set_tile_type( const tile_type& type ) noexcept;
    const tile_type& get_tile_type() const noexcept;

private:
    tile_type m_tile_type{ tile_type::empty };
};

//

class tank_object final
{
public:
    tank_object() = default;
    tank_object( const tank_type& type ) noexcept;

    void set_tank_type( const tank_type& type ) noexcept;
    const tank_type& get_tank_type() const noexcept;

private:
    tank_type m_tank_type{ tank_type::enemy };
};

//


class map_object final{};

//

class projectile final{};

//

class geometry final
{
public:
    geometry() = default;
    geometry( const QRect& rect, int rotation = 0 ) noexcept;

    bool intersects_with( const geometry& other ) const noexcept;
    bool intersects_with( const QRect& rect ) const noexcept;

    void set_pos( const QPoint& point ) noexcept;
    QPoint get_pos() const noexcept;

    void set_size( const QSize& size ) noexcept;
    QSize get_size() const noexcept;

    void set_rotation( int rotation ) noexcept;
    int get_rotation() const noexcept;

    const QRect& get_rect() const noexcept;

private:
    QRect m_rect;
    int m_rotation{ 0 };
};

//

enum class movement_direction{ left, right, up, down, none };

class movement final
{
public:
    movement() = default;
    movement( uint32_t step ) noexcept;

    void set_speed( uint32_t speed ) noexcept;
    uint32_t get_speed() const noexcept;

    void set_move_direction( const movement_direction& direction ) noexcept;
    const movement_direction& get_move_direction() const noexcept;
private:
    uint32_t m_speed{ 0 };
    movement_direction m_move_direction{ movement_direction::none };
};

//

class non_traversible final{};

//

class graphics final
{
public:
    graphics() = default;
    graphics( const QString& image_path, bool visible );

    void set_image_path( const QString& image_path );
    const QString& get_image_path() const noexcept;

    void set_visible( bool visible ) noexcept;
    bool get_visible() const noexcept;

private:
    QString m_image_path;
    bool m_visible{ true };
};

//

class health final
{
public:
    health() = default;
    explicit health( uint32_t max_health ) noexcept;

    void increase( uint32_t value ) noexcept;
    void decrease( uint32_t value ) noexcept;

    uint32_t get_health() const noexcept;
    uint32_t get_max_health() const noexcept;

    bool alive() const noexcept;

private:
    uint32_t m_health{ 0 };
    const uint32_t m_max_health{ 0 };
};

}// components

}// game

#endif
