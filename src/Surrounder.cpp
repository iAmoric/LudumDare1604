/*!
 * \file Surrounder.hpp
 * \brief Surround a object with lines
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "Surrounder.hpp"

/*!
 * \brief Constructor
 * \return None
 */
Surrounder::Surrounder() :
m_position(sf::Vector2f(0, 0)),
m_size(sf::Vector2u(0, 0)),
m_rectShape(m_size)
{
	// None
}

/*!
 * \brief Destructor
 * \return None
 */
Surrounder::~Surrounder() {
	// None
}

/*!
 * \brief Initialize the surrounder
 * \param pos The position of the rectangle
 * \param size The size of the rectangle
 * \return None
 */
void Surrounder::init(const sf::Vector2f & pos,
const sf::Vector2u & size) {

	m_cursorTexture.loadFromFile("../res/sprites/mouse_pointer.png");
	m_cursorSprite.setTexture(m_cursorTexture);

}

/*!
 * \brief Return the shape to surround an object
 * \return m_rectShape The shape
 */
sf::Sprite * Surrounder::getShape(sf::Vector2f pos) {
	m_cursorSprite.setPosition(pos);
	return &m_cursorSprite;
	//return &m_rectShape;
}