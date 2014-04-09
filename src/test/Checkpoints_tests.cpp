//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p1912 = uint256("0xfd2e3dd687bbe08854cbdb166515e4cca7705a5f3d255ca492701373a44fcaf8");
    uint256 p252690 = uint256("0x312ae083d12b9cb7879da4013bce73763de4c1403789f5459fab1c8170f18b74");
    BOOST_CHECK(Checkpoints::CheckBlock(1912, p1912));
    BOOST_CHECK(Checkpoints::CheckBlock(252690, p252690));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(1912, p252690));
    BOOST_CHECK(!Checkpoints::CheckBlock(252690, p1912));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(1912+1, p252690));
    BOOST_CHECK(Checkpoints::CheckBlock(252690+1, p1912));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 252690);
}

BOOST_AUTO_TEST_SUITE_END()
