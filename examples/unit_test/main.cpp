#include "test_core_graph.hpp"
#include "test_core_map.hpp"
#include "test_localizer_simple_road.hpp"
#include "test_localizer_gps2utm.hpp"
//#include "test_simple_localizer.hpp"

int main()
{
    // Please change 'NUN' to 'RUN' if you want run a test

    // Test 'dg::DirectedGraph'
    VVS_NUN_TEST(testDirectedGraphPtr());
    VVS_NUN_TEST(testDirectedGraphItr());

    // Test basic data structures
    VVS_NUN_TEST(testCoreLonLat());
    VVS_NUN_TEST(testCorePoint2ID());

    // Test 'dg::Map' and 'dg::MapPainter'
    VVS_NUN_TEST(testCoreNodeInfo());
    VVS_NUN_TEST(testCoreMap());
    VVS_NUN_TEST(testCoreMapPainter());

    // Test 'dg::SimpleRoadMap' and 'dg::SimpleRoadPainter'
    VVS_NUN_TEST(testLocSimpleRoadMap());
    VVS_NUN_TEST(testLocSimpleRoadPainter(true));

    // Test GPS and UTM conversion
    VVS_NUN_TEST(testLocRawGPS2UTM(dg::LonLat(128, 38), dg::Point2(412201.58, 4206286.76))); // Zone: 52S
    VVS_NUN_TEST(testLocRawGPS2UTM(dg::LonLat(127, 37), dg::Point2(322037.81, 4096742.06))); // Zone: 52S
    VVS_NUN_TEST(testLocRawUTM2GPS(dg::Point2(412201.58, 4206286.76), 52, false, dg::LonLat(128, 38)));
    VVS_NUN_TEST(testLocRawUTM2GPS(dg::Point2(322037.81, 4096742.06), 52, false, dg::LonLat(127, 37)));
    VVS_NUN_TEST(testLocRawUTM2GPS(dg::Point2(0, 0), 52, false, dg::LonLat(-1, -1)));

    VVS_NUN_TEST(testSimpleMetricLocalizer(true));

    return 0;
}