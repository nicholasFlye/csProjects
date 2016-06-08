package denfinder.model;

/**
 * Created by landon on 10/6/14.
 */
public class Coordinates {
    double latitude;
    double longitude;

    public Coordinates(double lat, double lon) {
        latitude = lat;
        longitude = lon;
    }

    public double getLongitude() {
        return longitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public double getLatitude() {
        return latitude;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }
    
    public static double distance(Coordinates a, Coordinates b) {
    	double distance = 0.0;
    	
    	// Square root of (x2-x1)^2 + (y2-y1)^2
    	distance  = Math.pow(b.getLatitude() - a.getLatitude(), 2);
    	distance += Math.pow(b.getLongitude() - a.getLongitude(), 2);
    	distance  = Math.sqrt(distance);
    	
    	return distance;
    }
    
}
