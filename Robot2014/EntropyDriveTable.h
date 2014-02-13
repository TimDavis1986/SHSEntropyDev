//entropy drive table 2014
const float left_lookup_radius[33] = {1.3 ,1.4 ,1.6 ,1.9 ,2.1 ,2.5 ,3.0 ,3.7 ,4.5 ,5.8 ,7.6 ,10.4 ,15.1 ,24.0 ,43.9 ,104.5 ,0 ,-104.5 , -43.9 ,-24.0 ,-15.1 ,-10.4 ,-7.6 ,-5.8 ,-4.5 ,-3.7 ,-3.0 ,-2.5 ,-2.1, -1.9 ,-1.6 ,-1.4 ,-1.3};
const float left_lookupx[33] = {-1.000	,-0.938	,-0.875	,-0.813	,-0.750	,-0.688	,-0.625	,-0.563	,-0.500	,-0.438	,-0.375	,-0.313	,-0.250	,-0.188	,-0.125	,-0.063	,0.000	,0.063	,0.125	,0.188	,0.250	,0.313	,0.375	,0.438	,0.500	,0.563	,0.625	,0.688	,0.750	,0.813	,0.875	,0.938	,1.000};
const float left_lookupy[33] = {1.000 ,0.938 ,0.875 ,0.813 ,0.750 ,0.688 ,0.625 ,0.563 ,0.500 ,0.438 ,0.375 ,0.313 ,0.250 ,0.188 ,0.125 ,0.063 ,0.000 ,-0.063 ,-0.125 ,-0.188 ,-0.250 ,-0.313 ,-0.375 ,-0.438 ,-0.500 ,-0.563 ,-0.625 ,-0.688 ,-0.750 ,-0.813 ,-0.875 ,-0.938 ,-1.000};
const float left_fast_njxy[33][33] = {
			{0.250,0.306,0.364,0.423,0.483,0.542,0.602,0.660,0.716,0.770,0.820,0.865,0.905,0.939,0.966,0.986,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000},
			{0.250,0.306,0.364,0.423,0.483,0.542,0.602,0.660,0.716,0.770,0.820,0.865,0.901,0.919,0.932,0.942,0.948,0.955,0.965,0.978,0.995,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000},
			{0.250,0.306,0.364,0.423,0.483,0.542,0.602,0.660,0.716,0.770,0.808,0.832,0.852,0.869,0.882,0.890,0.897,0.903,0.912,0.925,0.941,0.962,0.986,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000},			
			{0.250,0.306,0.364,0.423,0.483,0.542,0.602,0.660,0.706,0.735,0.762,0.784,0.803,0.819,0.831,0.839,0.845,0.851,0.860,0.872,0.887,0.906,0.929,0.955,0.985,1.000,1.000,1.000,1.000,1.000,1.000,1.000,1.000},
			{0.250,0.306,0.364,0.423,0.483,0.542,0.596,0.631,0.662,0.690,0.715,0.736,0.754,0.769,0.780,0.788,0.794,0.799,0.807,0.819,0.833,0.851,0.872,0.897,0.925,0.956,0.991,1.000,1.000,1.000,1.000,1.000,1.000},
			{0.250,0.306,0.364,0.423,0.483,0.522,0.558,0.590,0.619,0.646,0.669,0.689,0.705,0.719,0.730,0.737,0.742,0.748,0.755,0.765,0.779,0.796,0.816,0.839,0.865,0.894,0.927,0.962,1.000,1.000,1.000,1.000,1.000},
			{0.250,0.306,0.364,0.411,0.450,0.486,0.519,0.549,0.576,0.601,0.622,0.641,0.656,0.669,0.679,0.686,0.691,0.696,0.702,0.712,0.725,0.740,0.759,0.780,0.805,0.832,0.862,0.895,0.932,0.971,1.000,1.000,1.000},
			{0.250,0.300,0.341,0.380,0.416,0.449,0.480,0.508,0.533,0.556,0.576,0.593,0.607,0.619,0.628,0.634,0.639,0.644,0.650,0.659,0.671,0.685,0.702,0.722,0.745,0.770,0.798,0.829,0.862,0.898,0.937,0.978,1.000},
			{0.235,0.276,0.314,0.349,0.383,0.413,0.441,0.467,0.490,0.511,0.529,0.545,0.558,0.569,0.577,0.583,0.588,0.592,0.598,0.606,0.617,0.630,0.646,0.664,0.685,0.708,0.734,0.762,0.792,0.826,0.861,0.899,0.940},
			{0.214,0.251,0.286,0.319,0.349,0.377,0.403,0.426,0.447,0.466,0.483,0.497,0.509,0.519,0.527,0.532,0.536,0.540,0.545,0.553,0.563,0.575,0.589,0.606,0.625,0.646,0.669,0.695,0.723,0.753,0.786,0.820,0.858},
			{0.194,0.227,0.259,0.288,0.315,0.341,0.364,0.385,0.404,0.421,0.436,0.449,0.460,0.469,0.476,0.481,0.484,0.488,0.493,0.499,0.508,0.519,0.532,0.547,0.564,0.584,0.605,0.628,0.653,0.681,0.710,0.742,0.775},
			{0.175,0.203,0.231,0.257,0.282,0.304,0.325,0.344,0.361,0.377,0.390,0.402,0.411,0.419,0.425,0.430,0.433,0.436,0.440,0.446,0.454,0.464,0.476,0.489,0.504,0.521,0.540,0.561,0.584,0.608,0.634,0.663,0.693},
			{0.175,0.179,0.204,0.227,0.248,0.268,0.286,0.303,0.318,0.332,0.343,0.354,0.362,0.369,0.375,0.379,0.381,0.384,0.388,0.393,0.400,0.409,0.419,0.431,0.444,0.459,0.476,0.494,0.514,0.536,0.559,0.584,0.610},
			{0.175,0.175,0.176,0.196,0.215,0.232,0.248,0.262,0.275,0.287,0.297,0.306,0.313,0.319,0.324,0.327,0.330,0.332,0.335,0.340,0.346,0.353,0.362,0.373,0.384,0.397,0.412,0.427,0.445,0.463,0.483,0.505,0.528},
			{0.175,0.175,0.175,0.175,0.181,0.196,0.209,0.221,0.232,0.242,0.251,0.258,0.264,0.269,0.273,0.276,0.278,0.280,0.283,0.287,0.292,0.298,0.306,0.314,0.324,0.335,0.347,0.361,0.375,0.391,0.408,0.426,0.445},
			{0.175,0.175,0.175,0.175,0.175,0.175,0.175,0.180,0.189,0.197,0.204,0.210,0.215,0.219,0.223,0.225,0.227,0.228,0.230,0.234,0.238,0.243,0.249,0.256,0.264,0.273,0.283,0.294,0.306,0.318,0.332,0.347,0.363},
			{-0.600,-0.600,-0.600,-0.600,-0.450,-0.450,-0.450,-0.450,-0.300,-0.300,-0.300,-0.300,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.300,0.300,0.300,0.300,0.450,0.450,0.450,0.450,0.600,0.600,0.600,0.600},
			{-0.175,-0.175,-0.175,-0.175,-0.175,-0.175,-0.175,-0.180,-0.189,-0.197,-0.204,-0.210,-0.215,-0.219,-0.223,-0.225,-0.227,-0.228,-0.230,-0.234,-0.238,-0.243,-0.249,-0.256,-0.264,-0.273,-0.283,-0.294,-0.306,-0.318,-0.332,-0.347,-0.363},
			{-0.175,-0.175,-0.175,-0.175,-0.181,-0.196,-0.209,-0.221,-0.232,-0.242,-0.251,-0.258,-0.264,-0.269,-0.273,-0.276,-0.278,-0.280,-0.283,-0.287,-0.292,-0.298,-0.306,-0.314,-0.324,-0.335,-0.347,-0.361,-0.375,-0.391,-0.408,-0.426,-0.445},
			{-0.175,-0.175,-0.176,-0.196,-0.215,-0.232,-0.248,-0.262,-0.275,-0.287,-0.297,-0.306,-0.313,-0.319,-0.324,-0.327,-0.330,-0.332,-0.335,-0.340,-0.346,-0.353,-0.362,-0.373,-0.384,-0.397,-0.412,-0.427,-0.445,-0.463,-0.483,-0.505,-0.528},
			{-0.175,-0.179,-0.204,-0.227,-0.248,-0.268,-0.286,-0.303,-0.318,-0.332,-0.343,-0.354,-0.362,-0.369,-0.375,-0.379,-0.381,-0.384,-0.388,-0.393,-0.400,-0.409,-0.419,-0.431,-0.444,-0.459,-0.476,-0.494,-0.514,-0.536,-0.559,-0.584,-0.610},
			{-0.175,-0.203,-0.231,-0.257,-0.282,-0.304,-0.325,-0.344,-0.361,-0.377,-0.390,-0.402,-0.411,-0.419,-0.425,-0.430,-0.433,-0.436,-0.440,-0.446,-0.454,-0.464,-0.476,-0.489,-0.504,-0.521,-0.540,-0.561,-0.584,-0.608,-0.634,-0.663,-0.693},
			{-0.194,-0.227,-0.259,-0.288,-0.315,-0.341,-0.364,-0.385,-0.404,-0.421,-0.436,-0.449,-0.460,-0.469,-0.476,-0.481,-0.484,-0.488,-0.493,-0.499,-0.508,-0.519,-0.532,-0.547,-0.564,-0.584,-0.605,-0.628,-0.653,-0.681,-0.710,-0.742,-0.775},
			{-0.214,-0.251,-0.286,-0.319,-0.349,-0.377,-0.403,-0.426,-0.447,-0.466,-0.483,-0.497,-0.509,-0.519,-0.527,-0.532,-0.536,-0.540,-0.545,-0.553,-0.563,-0.575,-0.589,-0.606,-0.625,-0.646,-0.669,-0.695,-0.723,-0.753,-0.786,-0.820,-0.858},
			{-0.235,-0.276,-0.314,-0.349,-0.383,-0.413,-0.441,-0.467,-0.490,-0.511,-0.529,-0.545,-0.558,-0.569,-0.577,-0.583,-0.588,-0.592,-0.598,-0.606,-0.617,-0.630,-0.646,-0.664,-0.685,-0.708,-0.734,-0.762,-0.792,-0.826,-0.861,-0.899,-0.940},
			{-0.250,-0.300,-0.341,-0.380,-0.416,-0.449,-0.480,-0.508,-0.533,-0.556,-0.576,-0.593,-0.607,-0.619,-0.628,-0.634,-0.639,-0.644,-0.650,-0.659,-0.671,-0.685,-0.702,-0.722,-0.745,-0.770,-0.798,-0.829,-0.862,-0.898,-0.937,-0.978,-1.000},
			{-0.250,-0.306,-0.364,-0.411,-0.450,-0.486,-0.519,-0.549,-0.576,-0.601,-0.622,-0.641,-0.656,-0.669,-0.679,-0.686,-0.691,-0.696,-0.702,-0.712,-0.725,-0.740,-0.759,-0.780,-0.805,-0.832,-0.862,-0.895,-0.932,-0.971,-1.000,-1.000,-1.000},
			{-0.250,-0.306,-0.364,-0.423,-0.483,-0.522,-0.558,-0.590,-0.619,-0.646,-0.669,-0.689,-0.705,-0.719,-0.730,-0.737,-0.742,-0.748,-0.755,-0.765,-0.779,-0.796,-0.816,-0.839,-0.865,-0.894,-0.927,-0.962,-1.000,-1.000,-1.000,-1.000,-1.000},
			{-0.250,-0.306,-0.364,-0.423,-0.483,-0.542,-0.596,-0.631,-0.662,-0.690,-0.715,-0.736,-0.754,-0.769,-0.780,-0.788,-0.794,-0.799,-0.807,-0.819,-0.833,-0.851,-0.872,-0.897,-0.925,-0.956,-0.991,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000},
			{-0.250,-0.306,-0.364,-0.423,-0.483,-0.542,-0.602,-0.660,-0.706,-0.735,-0.762,-0.784,-0.803,-0.819,-0.831,-0.839,-0.845,-0.851,-0.860,-0.872,-0.887,-0.906,-0.929,-0.955,-0.985,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000},
			{-0.250,-0.306,-0.364,-0.423,-0.483,-0.542,-0.602,-0.660,-0.716,-0.770,-0.808,-0.832,-0.852,-0.869,-0.882,-0.890,-0.897,-0.903,-0.912,-0.925,-0.941,-0.962,-0.986,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000},
			{-0.250,-0.306,-0.364,-0.423,-0.483,-0.542,-0.602,-0.660,-0.716,-0.770,-0.820,-0.865,-0.901,-0.919,-0.932,-0.942,-0.948,-0.955,-0.965,-0.978,-0.995,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000},		
			{-0.250,-0.306,-0.364,-0.423,-0.483,-0.542,-0.602,-0.660,-0.716,-0.770,-0.820,-0.865,-0.905,-0.939,-0.966,-0.986,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000,-1.000}
};
