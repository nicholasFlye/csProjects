/**
 * Created on: 11/02/14
 * Author:     Isaac F. Fisher
 */
package denfinder.model;


public final class Common {
	
	//API keys
	//static final String EDUCATION_KEY = "3f82bf1cefee73674f3992dcc0cb20c3";   // Isaac's key
	//static final String EDUCATION_KEY = "277df245ae9d53f1cd36667569138498";
	static final String EDUCATION_KEY = "efb9b316554a9f2eb62e8eaafa8f9bfe"; //education key for wind
	
	
	static final String GEOCODING_KEY = "AIzaSyDmW7DnNY5wR_5DI4QwmS2Zxmg0q3Ba08E";
	static final String CENSUS_KEY = "247154b5274c2ce8ce3d4e6fbe375e33f3646afc";
	
	// Map data
	static final int MAP_DIVISIONS = 10;
	
	//CensusAPI result constants
	static final int RESULT_NOT_AVAILABLE = -1;
	
	// Algorithm input: General
	static final String INPUT_STRING_NO_PREFERENCE = "No Preference";
	static final double MINIMUM_RATING = -30.0;
	static final double MAXIMUM_RATING = 70.0;
	static final double RATING_ADJUSTMENT = 30.0;
	
	// Algorithm input: "Income Range"
	static final String INCOME_STRING_TIER_1 = "0-25";
	static final String INCOME_STRING_TIER_2 = "25-50";
	static final String INCOME_STRING_TIER_3 = "50-75";
	static final String INCOME_STRING_TIER_4 = "75-100";
	static final String INCOME_STRING_TIER_5 = "100+";
	
	static final int INCOME_TIER_1 = 0;
	static final int INCOME_TIER_2 = 25000;
	static final int INCOME_TIER_3 = 50000;
	static final int INCOME_TIER_4 = 75000;
	static final int INCOME_TIER_5 = 100000;
	
	static final double INCOME_RATING_BASE_NEAR = 1.25;
	static final double INCOME_RATING_BASE_FAR  = 1.50;
	static final double INCOME_RATING_BASE_FARTHEST = 2.50;
	static final double INCOME_RATING_DIFFERENCE_NEAR = 30000;
	static final double INCOME_RATING_DIFFERENCE_FAR  = 45000;
	static final double INCOME_RATING_DIVIDEND  = 10000;
	
	static final double MATCHING_INCOME_POINTS = 15;
	
	
	// Algorithm input: "Age Range"
	static final String AGE_STRING_TIER_1 = "13-19";
	static final String AGE_STRING_TIER_2 = "20-29";
	static final String AGE_STRING_TIER_3 = "30-39";
	static final String AGE_STRING_TIER_4 = "40-49";
	static final String AGE_STRING_TIER_5 = "50-59";
	static final String AGE_STRING_TIER_6 = "60+";
	
	static final double AGE_TIER_1 = 13;
	static final double AGE_TIER_2 = 20;
	static final double AGE_TIER_3 = 30;
	static final double AGE_TIER_4 = 40;
	static final double AGE_TIER_5 = 50;
	static final double AGE_TIER_6 = 60;
	
	static final double AGE_RATING_BASE_NEAR = 1.50;
	static final double AGE_RATING_BASE_FAR  = 2.0;
	static final double AGE_RATING_BASE_FARTHEST = 3.50;
	static final double AGE_RATING_DIFFERENCE_NEAR = 12.5;
	static final double AGE_RATING_DIFFERENCE_FAR  = 20.0;
	static final double AGE_RATING_DIVIDEND  = 7.5;
	
	static final double MATCHING_AGE_POINTS = 15;
	
	
	// Algorithm input: "Relationship Status"
	static final String RELATIONSHIP_STRING_SINGLE  = "Single";
	static final String RELATIONSHIP_STRING_MARRIED = "Married";
	
	static final double RELATIONSHIP_MINIMUM_RATIO = 1.2;
	
	static final double RELATIONSHIP_MIN_POINTS  = -15;
	static final double RELATIONSHIP_MAX_POINTS  = 15;
	static final double RELATIONSHIP_BASE_POINTS = 3;
	
	
	// Algorithm input: "Importance of School System Quality"
	static final String SCHOOL_IMPORTANCE_STRING_LOW    = "Not Very Important";
	static final String SCHOOL_IMPORTANCE_STRING_MEDIUM = "Somewhat Important";
	static final String SCHOOL_IMPORTANCE_STRING_HIGH   = "Very Important";
	
	static final double SCHOOL_MAX_DISTANCE = 1.0;
	
	static final double SCHOOL_TEST_SCORE_LOW = 4;
	static final double SCHOOL_TEST_SCORE_HIGH = 8;
	
	static final double SCHOOL_QUALITY_BONUS_POINTS = 3.0;
	static final double SCHOOL_SCORE_MULTIPLIER = 0.5;
	
	static final double SCHOOL_MAX_POINTS_VERY_IMPORTANT     = 30.0;
	static final double SCHOOL_MAX_POINTS_SOMEWHAT_IMPORTANT = 20.0;
	static final double SCHOOL_MAX_POINTS_NOT_VERY_IMPORTANT = 10.0;
	
	static final double SCHOOl_QUALITY_MULTIPLIER_VERY_IMPORTANT     = 1.5;
	static final double SCHOOL_QUALITY_MULTIPLIER_SOMEWHAT_IMPORTANT = 1.0;
	static final double SCHOOL_QUALITY_MULTIPLIER_NOT_VERY_IMPORTANT = 0.5;
	static final double SCHOOL_QUALITY_MULTIPLIER_NO_PREFERENCE      = 0.0;
}
