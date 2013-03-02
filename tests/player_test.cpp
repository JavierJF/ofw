/*************************************************************************
* Open Fantasy World is a MMORPG where the players will live in community.
* Copyright (C) 2012-2013 Víctor Ramirez de la Corte <virako.9@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Foobar is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#define BOOST_TEST_MODULE playertests
#include <boost/test/included/unit_test.hpp>

#include "character.hpp"
#include "player.hpp"
#include "cte.hpp"

using namespace hw;

struct StructPlayer {
    Player *p;
    StructPlayer() { p = new Player(); } // setUp
    ~StructPlayer() { delete(p); }  // tearDown
};

// Height
BOOST_FIXTURE_TEST_SUITE (player_height, StructPlayer)

BOOST_AUTO_TEST_CASE (height_increment) {
    p->set_rel_height(1);
    BOOST_CHECK( p->get_height() == HEIGHT_DEFAULT + 1 );
}

BOOST_AUTO_TEST_CASE (height_decrement) {
    p->set_rel_height(-1);
    BOOST_CHECK( p->get_height() == HEIGHT_DEFAULT - 1 );
}

BOOST_AUTO_TEST_CASE (height_increment_out_domain) {
    p->set_height(HEIGHT_MAX);
    BOOST_CHECK_THROW( p->set_rel_height(1), domain_error );
}

BOOST_AUTO_TEST_CASE (height_decrement_out_domain) {
    p->set_height(HEIGHT_MIN);
    BOOST_CHECK_THROW( p->set_rel_height(-1), domain_error );
}

BOOST_AUTO_TEST_SUITE_END( )


// Width
BOOST_FIXTURE_TEST_SUITE (player_width, StructPlayer)

BOOST_AUTO_TEST_CASE (width_increment) {
    p->set_rel_width(1);
    BOOST_CHECK( p->get_width() == WIDTH_DEFAULT + 1 );
}

BOOST_AUTO_TEST_CASE (width_decrement) {
    p->set_rel_width(-1);
    BOOST_CHECK( p->get_width() == WIDTH_DEFAULT - 1 );
}

BOOST_AUTO_TEST_CASE (width_increment_out_domain) {
    p->set_width(WIDTH_MAX);
    BOOST_CHECK_THROW( p->set_rel_width(1), domain_error );
}

BOOST_AUTO_TEST_CASE (width_decrement_out_domain) {
    p->set_width(WIDTH_MIN);
    BOOST_CHECK_THROW( p->set_rel_width(-1), domain_error );
}

BOOST_AUTO_TEST_SUITE_END( )
