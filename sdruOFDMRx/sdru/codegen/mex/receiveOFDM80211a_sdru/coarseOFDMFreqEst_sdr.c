/*
 * coarseOFDMFreqEst_sdr.c
 *
 * Code generation for function 'coarseOFDMFreqEst_sdr'
 *
 * C source code generated on: Tue Oct  8 14:08:18 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDM80211a_sdru.h"
#include "coarseOFDMFreqEst_sdr.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo re_emlrtRSI = { 28, "coarseOFDMFreqEst_sdr",
  "/opt/MATLAB/R2013a/toolbox/comm/commdemos/private/coarseOFDMFreqEst_sdr.m" };

static emlrtBCInfo y_emlrtBCI = { 1, 15, 28, 33, "", "coarseOFDMFreqEst_sdr",
  "/opt/MATLAB/R2013a/toolbox/comm/commdemos/private/coarseOFDMFreqEst_sdr.m", 0
};

/* Function Definitions */
void freqCorrectOFDM(b_struct_T *estimate, const creal_T rFrame[1280], creal_T
                     b_rFreqShifted[1280])
{
  int32_T i;
  real_T r;
  int32_T exitg1;
  int32_T estimate_idx_0;
  real_T y_re;
  real_T y_im;
  static const real_T b[1280] = { 0.0, 1.0E-6, 2.0E-6, 3.0E-6, 4.0E-6,
    4.9999999999999996E-6, 6.0E-6, 7.0E-6, 8.0E-6, 9.0E-6, 9.9999999999999991E-6,
    1.1E-5, 1.2E-5, 1.3E-5, 1.4E-5, 1.4999999999999999E-5, 1.6E-5, 1.7E-5,
    1.8E-5, 1.8999999999999998E-5, 1.9999999999999998E-5, 2.1E-5, 2.2E-5, 2.3E-5,
    2.4E-5, 2.4999999999999998E-5, 2.6E-5, 2.7E-5, 2.8E-5, 2.9E-5,
    2.9999999999999997E-5, 3.1E-5, 3.2E-5, 3.2999999999999996E-5, 3.4E-5, 3.5E-5,
    3.6E-5, 3.7E-5, 3.7999999999999995E-5, 3.9E-5, 3.9999999999999996E-5, 4.1E-5,
    4.2E-5, 4.2999999999999995E-5, 4.4E-5, 4.4999999999999996E-5, 4.6E-5, 4.7E-5,
    4.8E-5, 4.9E-5, 4.9999999999999996E-5, 5.1E-5, 5.2E-5, 5.3E-5, 5.4E-5,
    5.4999999999999995E-5, 5.6E-5, 5.6999999999999996E-5, 5.8E-5, 5.9E-5,
    5.9999999999999995E-5, 6.1E-5, 6.2E-5, 6.3E-5, 6.4E-5, 6.5E-5,
    6.5999999999999992E-5, 6.7E-5, 6.8E-5, 6.9E-5, 7.0E-5, 7.0999999999999991E-5,
    7.2E-5, 7.3E-5, 7.4E-5, 7.5E-5, 7.5999999999999991E-5, 7.7E-5, 7.8E-5,
    7.9E-5, 7.9999999999999993E-5, 8.099999999999999E-5, 8.2E-5, 8.3E-5, 8.4E-5,
    8.4999999999999993E-5, 8.599999999999999E-5, 8.7E-5, 8.8E-5, 8.9E-5,
    8.9999999999999992E-5, 9.0999999999999989E-5, 9.2E-5, 9.3E-5, 9.4E-5,
    9.4999999999999992E-5, 9.6E-5, 9.7E-5, 9.8E-5, 9.9E-5, 9.9999999999999991E-5,
    0.000101, 0.000102, 0.000103, 0.000104, 0.00010499999999999999, 0.000106,
    0.000107, 0.000108, 0.00010899999999999999, 0.00010999999999999999, 0.000111,
    0.000112, 0.000113, 0.00011399999999999999, 0.00011499999999999999, 0.000116,
    0.000117, 0.000118, 0.00011899999999999999, 0.00011999999999999999, 0.000121,
    0.000122, 0.00012299999999999998, 0.000124, 0.000125, 0.000126, 0.000127,
    0.000128, 0.000129, 0.00013, 0.00013099999999999999, 0.00013199999999999998,
    0.000133, 0.000134, 0.000135, 0.000136, 0.000137, 0.000138, 0.000139,
    0.00014, 0.00014099999999999998, 0.00014199999999999998, 0.000143, 0.000144,
    0.000145, 0.000146, 0.000147, 0.000148, 0.000149, 0.00015,
    0.00015099999999999998, 0.00015199999999999998, 0.000153, 0.000154, 0.000155,
    0.000156, 0.000157, 0.000158, 0.000159, 0.00015999999999999999,
    0.00016099999999999998, 0.00016199999999999998, 0.000163, 0.000164, 0.000165,
    0.000166, 0.000167, 0.000168, 0.000169, 0.00016999999999999999,
    0.00017099999999999998, 0.00017199999999999998, 0.000173, 0.000174, 0.000175,
    0.000176, 0.000177, 0.000178, 0.000179, 0.00017999999999999998,
    0.00018099999999999998, 0.00018199999999999998, 0.000183, 0.000184, 0.000185,
    0.000186, 0.000187, 0.000188, 0.00018899999999999999, 0.00018999999999999998,
    0.00019099999999999998, 0.000192, 0.000193, 0.000194, 0.000195, 0.000196,
    0.000197, 0.000198, 0.00019899999999999999, 0.00019999999999999998,
    0.00020099999999999998, 0.000202, 0.000203, 0.000204, 0.000205, 0.000206,
    0.000207, 0.000208, 0.00020899999999999998, 0.00020999999999999998,
    0.00021099999999999998, 0.000212, 0.000213, 0.000214, 0.000215, 0.000216,
    0.000217, 0.00021799999999999999, 0.00021899999999999998,
    0.00021999999999999998, 0.00022099999999999998, 0.000222, 0.000223, 0.000224,
    0.000225, 0.000226, 0.000227, 0.00022799999999999999, 0.00022899999999999998,
    0.00022999999999999998, 0.00023099999999999998, 0.000232, 0.000233, 0.000234,
    0.000235, 0.000236, 0.000237, 0.00023799999999999998, 0.00023899999999999998,
    0.00023999999999999998, 0.00024099999999999998, 0.000242, 0.000243, 0.000244,
    0.000245, 0.00024599999999999996, 0.000247, 0.000248, 0.000249, 0.00025,
    0.000251, 0.000252, 0.00025299999999999997, 0.000254, 0.00025499999999999996,
    0.000256, 0.000257, 0.000258, 0.000259, 0.00026, 0.000261,
    0.00026199999999999997, 0.000263, 0.00026399999999999997, 0.000265, 0.000266,
    0.000267, 0.000268, 0.000269, 0.00027, 0.000271, 0.000272,
    0.00027299999999999997, 0.000274, 0.00027499999999999996, 0.000276, 0.000277,
    0.000278, 0.000279, 0.00028, 0.000281, 0.00028199999999999997, 0.000283,
    0.00028399999999999996, 0.000285, 0.000286, 0.000287, 0.000288, 0.000289,
    0.00029, 0.00029099999999999997, 0.000292, 0.00029299999999999997, 0.000294,
    0.00029499999999999996, 0.000296, 0.000297, 0.000298, 0.000299, 0.0003,
    0.000301, 0.00030199999999999997, 0.000303, 0.00030399999999999996, 0.000305,
    0.000306, 0.000307, 0.000308, 0.000309, 0.00031, 0.00031099999999999997,
    0.000312, 0.00031299999999999996, 0.000314, 0.00031499999999999996, 0.000316,
    0.000317, 0.000318, 0.000319, 0.00031999999999999997, 0.000321,
    0.00032199999999999997, 0.000323, 0.00032399999999999996, 0.000325, 0.000326,
    0.000327, 0.000328, 0.000329, 0.00033, 0.00033099999999999997, 0.000332,
    0.00033299999999999996, 0.000334, 0.000335, 0.000336, 0.000337, 0.000338,
    0.000339, 0.00033999999999999997, 0.000341, 0.00034199999999999996, 0.000343,
    0.00034399999999999996, 0.000345, 0.000346, 0.000347, 0.000348,
    0.00034899999999999997, 0.00035, 0.00035099999999999997, 0.000352,
    0.00035299999999999996, 0.000354, 0.000355, 0.000356, 0.000357, 0.000358,
    0.000359, 0.00035999999999999997, 0.000361, 0.00036199999999999996, 0.000363,
    0.00036399999999999996, 0.000365, 0.000366, 0.000367, 0.000368,
    0.00036899999999999997, 0.00037, 0.00037099999999999996, 0.000372,
    0.00037299999999999996, 0.000374, 0.000375, 0.000376, 0.000377,
    0.00037799999999999997, 0.000379, 0.00037999999999999997, 0.000381,
    0.00038199999999999996, 0.000383, 0.000384, 0.000385, 0.000386, 0.000387,
    0.000388, 0.00038899999999999997, 0.00039, 0.00039099999999999996, 0.000392,
    0.00039299999999999996, 0.000394, 0.000395, 0.000396, 0.000397,
    0.00039799999999999997, 0.000399, 0.00039999999999999996, 0.000401,
    0.00040199999999999996, 0.000403, 0.000404, 0.000405, 0.000406,
    0.00040699999999999997, 0.000408, 0.00040899999999999997, 0.00041,
    0.00041099999999999996, 0.000412, 0.00041299999999999996, 0.000414, 0.000415,
    0.000416, 0.000417, 0.00041799999999999997, 0.000419, 0.00041999999999999996,
    0.000421, 0.00042199999999999996, 0.000423, 0.000424, 0.000425, 0.000426,
    0.00042699999999999997, 0.000428, 0.00042899999999999997, 0.00043,
    0.00043099999999999996, 0.000432, 0.00043299999999999995, 0.000434, 0.000435,
    0.00043599999999999997, 0.000437, 0.00043799999999999997, 0.000439,
    0.00043999999999999996, 0.000441, 0.00044199999999999996, 0.000443, 0.000444,
    0.000445, 0.000446, 0.00044699999999999997, 0.000448, 0.00044899999999999996,
    0.00045, 0.00045099999999999996, 0.000452, 0.000453, 0.000454, 0.000455,
    0.00045599999999999997, 0.000457, 0.00045799999999999997, 0.000459,
    0.00045999999999999996, 0.000461, 0.00046199999999999995, 0.000463, 0.000464,
    0.00046499999999999997, 0.000466, 0.00046699999999999997, 0.000468,
    0.00046899999999999996, 0.00047, 0.00047099999999999996, 0.000472, 0.000473,
    0.000474, 0.000475, 0.00047599999999999997, 0.000477, 0.00047799999999999996,
    0.000479, 0.00047999999999999996, 0.000481, 0.00048199999999999995, 0.000483,
    0.000484, 0.00048499999999999997, 0.000486, 0.00048699999999999997, 0.000488,
    0.000489, 0.00049, 0.000491, 0.00049199999999999992, 0.000493, 0.000494,
    0.000495, 0.000496, 0.00049699999999999994, 0.000498, 0.000499, 0.0005,
    0.00050099999999999993, 0.000502, 0.000503, 0.000504, 0.000505,
    0.00050599999999999994, 0.000507, 0.000508, 0.000509, 0.00050999999999999993,
    0.000511, 0.000512, 0.000513, 0.000514, 0.00051499999999999994, 0.000516,
    0.000517, 0.000518, 0.00051899999999999993, 0.00052, 0.000521, 0.000522,
    0.000523, 0.00052399999999999994, 0.000525, 0.000526, 0.000527,
    0.00052799999999999993, 0.000529, 0.00053, 0.000531, 0.000532,
    0.00053299999999999995, 0.000534, 0.000535, 0.000536, 0.00053699999999999993,
    0.000538, 0.000539, 0.00054, 0.00054099999999999992, 0.000542, 0.000543,
    0.000544, 0.000545, 0.00054599999999999994, 0.000547, 0.000548, 0.000549,
    0.00054999999999999992, 0.000551, 0.000552, 0.000553, 0.000554,
    0.00055499999999999994, 0.000556, 0.000557, 0.000558, 0.00055899999999999993,
    0.00056, 0.000561, 0.000562, 0.000563, 0.00056399999999999994, 0.000565,
    0.000566, 0.000567, 0.00056799999999999993, 0.000569, 0.00057, 0.000571,
    0.000572, 0.00057299999999999994, 0.000574, 0.000575, 0.000576,
    0.00057699999999999993, 0.000578, 0.000579, 0.00058, 0.000581,
    0.00058199999999999994, 0.000583, 0.000584, 0.000585, 0.00058599999999999993,
    0.000587, 0.000588, 0.000589, 0.00058999999999999992, 0.00059099999999999995,
    0.000592, 0.000593, 0.000594, 0.00059499999999999993, 0.000596, 0.000597,
    0.000598, 0.00059899999999999992, 0.0006, 0.000601, 0.000602, 0.000603,
    0.00060399999999999994, 0.000605, 0.000606, 0.000607, 0.00060799999999999993,
    0.000609, 0.00061, 0.000611, 0.000612, 0.00061299999999999994, 0.000614,
    0.000615, 0.000616, 0.00061699999999999993, 0.000618, 0.000619, 0.00062,
    0.000621, 0.00062199999999999994, 0.000623, 0.000624, 0.000625,
    0.00062599999999999993, 0.000627, 0.000628, 0.000629, 0.00062999999999999992,
    0.00063099999999999994, 0.000632, 0.000633, 0.000634, 0.00063499999999999993,
    0.000636, 0.000637, 0.000638, 0.00063899999999999992, 0.00064, 0.000641,
    0.000642, 0.000643, 0.000644, 0.000645, 0.000646, 0.000647, 0.000648,
    0.00064900000000000005, 0.00065, 0.000651, 0.000652, 0.000653, 0.000654,
    0.000655, 0.000656, 0.000657, 0.000658, 0.000659, 0.00066, 0.000661,
    0.000662, 0.000663, 0.000664, 0.000665, 0.000666, 0.000667, 0.000668,
    0.000669, 0.00067, 0.000671, 0.000672, 0.000673, 0.000674, 0.000675,
    0.000676, 0.000677, 0.000678, 0.000679, 0.00068, 0.000681, 0.000682,
    0.000683, 0.000684, 0.000685, 0.000686, 0.000687, 0.000688, 0.000689,
    0.00069, 0.000691, 0.000692, 0.000693, 0.000694, 0.000695, 0.000696,
    0.000697, 0.00069799999999999994, 0.000699, 0.0007, 0.000701, 0.000702,
    0.000703, 0.000704, 0.000705, 0.000706, 0.000707, 0.000708, 0.000709,
    0.00071, 0.000711, 0.000712, 0.000713, 0.000714, 0.000715, 0.000716,
    0.000717, 0.000718, 0.000719, 0.00072, 0.000721, 0.000722, 0.000723,
    0.000724, 0.000725, 0.000726, 0.000727, 0.000728, 0.000729, 0.00073,
    0.000731, 0.000732, 0.000733, 0.000734, 0.000735, 0.000736, 0.000737,
    0.000738, 0.000739, 0.00074, 0.000741, 0.000742, 0.000743, 0.000744,
    0.000745, 0.000746, 0.00074699999999999994, 0.000748, 0.000749, 0.00075,
    0.000751, 0.000752, 0.000753, 0.000754, 0.000755, 0.00075599999999999994,
    0.000757, 0.000758, 0.000759, 0.00076, 0.000761, 0.000762, 0.000763,
    0.000764, 0.000765, 0.000766, 0.000767, 0.000768, 0.000769, 0.00077,
    0.000771, 0.000772, 0.000773, 0.000774, 0.000775, 0.000776, 0.000777,
    0.000778, 0.000779, 0.00078, 0.000781, 0.000782, 0.000783, 0.000784,
    0.000785, 0.000786, 0.000787, 0.000788, 0.000789, 0.00079, 0.000791,
    0.000792, 0.000793, 0.000794, 0.00079499999999999992, 0.000796, 0.000797,
    0.000798, 0.000799, 0.00079999999999999993, 0.00080100000000000006, 0.000802,
    0.000803, 0.000804, 0.00080499999999999994, 0.000806, 0.000807, 0.000808,
    0.000809, 0.00081, 0.000811, 0.000812, 0.00081299999999999992, 0.000814,
    0.000815, 0.000816, 0.000817, 0.00081799999999999993, 0.00081900000000000007,
    0.00082, 0.000821, 0.000822, 0.000823, 0.000824, 0.000825,
    0.00082599999999999991, 0.000827, 0.000828, 0.000829, 0.00083,
    0.00083099999999999992, 0.00083200000000000006, 0.000833, 0.000834, 0.000835,
    0.00083599999999999994, 0.00083700000000000007, 0.000838, 0.000839, 0.00084,
    0.000841, 0.000842, 0.000843, 0.00084399999999999992, 0.000845, 0.000846,
    0.000847, 0.000848, 0.00084899999999999993, 0.00085000000000000006, 0.000851,
    0.000852, 0.000853, 0.00085399999999999994, 0.000855, 0.000856, 0.000857,
    0.000858, 0.000859, 0.00086, 0.000861, 0.00086199999999999992, 0.000863,
    0.000864, 0.000865, 0.000866, 0.00086699999999999993, 0.00086800000000000006,
    0.000869, 0.00087, 0.000871, 0.00087199999999999995, 0.000873, 0.000874,
    0.00087499999999999991, 0.000876, 0.000877, 0.000878, 0.000879,
    0.00087999999999999992, 0.00088100000000000006, 0.000882, 0.000883, 0.000884,
    0.00088499999999999994, 0.00088600000000000007, 0.000887, 0.000888, 0.000889,
    0.00089, 0.000891, 0.000892, 0.00089299999999999991, 0.000894, 0.000895,
    0.000896, 0.000897, 0.00089799999999999993, 0.00089900000000000006, 0.0009,
    0.000901, 0.000902, 0.00090299999999999994, 0.000904, 0.000905, 0.000906,
    0.000907, 0.000908, 0.000909, 0.00091, 0.00091099999999999992, 0.000912,
    0.000913, 0.000914, 0.000915, 0.00091599999999999993, 0.00091700000000000006,
    0.000918, 0.000919, 0.00092, 0.00092099999999999994, 0.000922, 0.000923,
    0.00092399999999999991, 0.000925, 0.000926, 0.000927, 0.000928,
    0.00092899999999999992, 0.00093, 0.000931, 0.000932, 0.000933,
    0.00093399999999999993, 0.00093500000000000007, 0.000936, 0.000937, 0.000938,
    0.000939, 0.00094, 0.000941, 0.00094199999999999991, 0.000943, 0.000944,
    0.000945, 0.000946, 0.00094699999999999993, 0.00094800000000000006, 0.000949,
    0.00095, 0.000951, 0.00095199999999999994, 0.000953, 0.000954, 0.000955,
    0.000956, 0.000957, 0.000958, 0.000959, 0.00095999999999999992, 0.000961,
    0.000962, 0.000963, 0.000964, 0.00096499999999999993, 0.00096600000000000006,
    0.000967, 0.000968, 0.000969, 0.00096999999999999994, 0.000971, 0.000972,
    0.00097299999999999991, 0.000974, 0.000975, 0.000976, 0.000977, 0.000978,
    0.000979, 0.00098, 0.000981, 0.000982, 0.000983, 0.000984, 0.000985,
    0.000986, 0.000987, 0.000988, 0.00098899999999999986, 0.00099, 0.000991,
    0.000992, 0.000993, 0.000994, 0.000995, 0.000996, 0.000997, 0.000998,
    0.00099899999999999989, 0.001, 0.001001, 0.0010019999999999999, 0.001003,
    0.0010040000000000001, 0.001005, 0.001006, 0.001007, 0.001008, 0.001009,
    0.00101, 0.001011, 0.0010119999999999999, 0.001013, 0.001014, 0.001015,
    0.001016, 0.0010170000000000001, 0.001018, 0.001019, 0.00102, 0.001021,
    0.001022, 0.001023, 0.001024, 0.0010249999999999999, 0.001026, 0.001027,
    0.001028, 0.001029, 0.00103, 0.001031, 0.001032, 0.001033, 0.001034,
    0.001035, 0.001036, 0.001037, 0.001038, 0.001039, 0.00104, 0.001041,
    0.001042, 0.001043, 0.001044, 0.001045, 0.001046, 0.001047,
    0.0010479999999999999, 0.001049, 0.00105, 0.001051, 0.001052, 0.001053,
    0.001054, 0.001055, 0.001056, 0.001057, 0.001058, 0.001059, 0.00106,
    0.0010609999999999999, 0.001062, 0.001063, 0.001064, 0.001065,
    0.0010659999999999999, 0.001067, 0.001068, 0.001069, 0.00107, 0.001071,
    0.001072, 0.001073, 0.0010739999999999999, 0.001075, 0.001076, 0.001077,
    0.001078, 0.001079, 0.00108, 0.001081, 0.001082, 0.001083, 0.001084,
    0.001085, 0.001086, 0.0010869999999999999, 0.001088, 0.001089, 0.00109,
    0.001091, 0.001092, 0.001093, 0.001094, 0.001095, 0.001096,
    0.0010969999999999999, 0.001098, 0.001099, 0.0011, 0.001101, 0.001102,
    0.001103, 0.001104, 0.001105, 0.001106, 0.001107, 0.001108, 0.001109,
    0.0011099999999999999, 0.001111, 0.001112, 0.001113, 0.001114,
    0.0011149999999999999, 0.001116, 0.001117, 0.001118, 0.001119, 0.00112,
    0.001121, 0.001122, 0.0011229999999999999, 0.001124, 0.001125, 0.001126,
    0.001127, 0.001128, 0.001129, 0.00113, 0.001131, 0.001132, 0.001133,
    0.001134, 0.001135, 0.0011359999999999999, 0.001137, 0.001138, 0.001139,
    0.00114, 0.001141, 0.001142, 0.001143, 0.001144, 0.001145,
    0.0011459999999999999, 0.001147, 0.001148, 0.001149, 0.00115, 0.001151,
    0.001152, 0.001153, 0.001154, 0.001155, 0.001156, 0.001157, 0.001158,
    0.0011589999999999999, 0.00116, 0.001161, 0.001162, 0.001163,
    0.0011639999999999999, 0.001165, 0.001166, 0.001167, 0.001168, 0.001169,
    0.00117, 0.001171, 0.0011719999999999999, 0.001173, 0.001174, 0.001175,
    0.001176, 0.0011769999999999999, 0.001178, 0.001179, 0.00118, 0.001181,
    0.0011819999999999999, 0.001183, 0.001184, 0.001185, 0.001186, 0.001187,
    0.001188, 0.001189, 0.00119, 0.001191, 0.001192, 0.001193, 0.001194,
    0.0011949999999999999, 0.001196, 0.001197, 0.001198, 0.001199, 0.0012,
    0.001201, 0.001202, 0.001203, 0.001204, 0.001205, 0.001206, 0.001207,
    0.0012079999999999999, 0.001209, 0.00121, 0.001211, 0.001212,
    0.0012129999999999999, 0.001214, 0.001215, 0.001216, 0.001217, 0.001218,
    0.001219, 0.00122, 0.0012209999999999999, 0.001222, 0.001223, 0.001224,
    0.001225, 0.0012259999999999999, 0.001227, 0.001228, 0.001229, 0.00123,
    0.0012309999999999999, 0.001232, 0.001233, 0.001234, 0.001235, 0.001236,
    0.001237, 0.001238, 0.001239, 0.00124, 0.001241, 0.001242, 0.001243,
    0.0012439999999999999, 0.001245, 0.001246, 0.001247, 0.001248, 0.001249,
    0.00125, 0.001251, 0.001252, 0.001253, 0.001254, 0.001255, 0.001256,
    0.0012569999999999999, 0.001258, 0.001259, 0.00126, 0.001261,
    0.0012619999999999999, 0.001263, 0.001264, 0.001265, 0.001266, 0.001267,
    0.001268, 0.001269, 0.00127, 0.001271, 0.001272, 0.001273, 0.001274,
    0.0012749999999999999, 0.001276, 0.001277, 0.001278, 0.001279 };

  real_T rFreqShifted_im;
  if (estimate->numProcessed < 15.0) {
    i = (int32_T)estimate->numProcessed;
    emlrtDynamicBoundsCheckFastR2012b(i, 1, 15, &y_emlrtBCI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&re_emlrtRSI, emlrtRootTLSGlobal);
    r = estimate->frequency[0];
    i = 2;
    do {
      exitg1 = 0;
      estimate_idx_0 = (int32_T)estimate->numProcessed;
      if (i <= estimate_idx_0) {
        r += estimate->frequency[i - 1];
        i++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    estimate->frequencyMA = r / (real_T)(int32_T)estimate->numProcessed;
    emlrtPopRtStackR2012b(&re_emlrtRSI, emlrtRootTLSGlobal);
    y_re = estimate->frequencyMA * 0.0;
    y_im = estimate->frequencyMA;
    for (i = 0; i < 1280; i++) {
      b_rFreqShifted[i].re = b[i] * y_re;
      b_rFreqShifted[i].im = b[i] * y_im;
      r = muDoubleScalarExp(b_rFreqShifted[i].re / 2.0);
      rFreqShifted_im = b_rFreqShifted[i].im;
      b_rFreqShifted[i].re = r * (r * muDoubleScalarCos(b_rFreqShifted[i].im));
      b_rFreqShifted[i].im = r * (r * muDoubleScalarSin(rFreqShifted_im));
      r = b_rFreqShifted[i].re;
      rFreqShifted_im = b_rFreqShifted[i].im;
      b_rFreqShifted[i].re = b_rFreqShifted[i].re * rFrame[i].re -
        b_rFreqShifted[i].im * rFrame[i].im;
      b_rFreqShifted[i].im = r * rFrame[i].im + rFreqShifted_im * rFrame[i].re;
    }
  } else {
    r = estimate->frequency[0];
    for (i = 0; i < 14; i++) {
      r += estimate->frequency[i + 1];
    }

    estimate->frequencyMA = r / 15.0;
    y_re = estimate->frequencyMA * 0.0;
    y_im = estimate->frequencyMA;
    for (i = 0; i < 1280; i++) {
      b_rFreqShifted[i].re = b[i] * y_re;
      b_rFreqShifted[i].im = b[i] * y_im;
      r = muDoubleScalarExp(b_rFreqShifted[i].re / 2.0);
      rFreqShifted_im = b_rFreqShifted[i].im;
      b_rFreqShifted[i].re = r * (r * muDoubleScalarCos(b_rFreqShifted[i].im));
      b_rFreqShifted[i].im = r * (r * muDoubleScalarSin(rFreqShifted_im));
      r = b_rFreqShifted[i].re;
      rFreqShifted_im = b_rFreqShifted[i].im;
      b_rFreqShifted[i].re = b_rFreqShifted[i].re * rFrame[i].re -
        b_rFreqShifted[i].im * rFrame[i].im;
      b_rFreqShifted[i].im = r * rFrame[i].im + rFreqShifted_im * rFrame[i].re;
    }
  }
}

/* End of code generation (coarseOFDMFreqEst_sdr.c) */
