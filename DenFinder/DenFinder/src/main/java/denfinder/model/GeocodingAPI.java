package denfinder.model;

import org.apache.commons.lang3.tuple.Pair;
import org.json.JSONArray;
import org.json.JSONObject;
import org.springframework.web.util.UriUtils;

import java.io.IOException;

/**
 * Created by landon on 10/6/14.
 */
public class GeocodingAPI extends ApiCall {
    public static Pair<Coordinates, Coordinates> getCoordinates(String address) throws IOException {
        String url = "https://maps.googleapis.com/maps/api/geocode/json?address=" +
                UriUtils.encodeFragment(address, "UTF-8") + "&sensor=false&key=" + Common.GEOCODING_KEY;

        //TODO for error checking, verify status=OK

        JSONObject json = loadJSON(url);
        JSONObject location = json.getJSONArray("results")
                .getJSONObject(0)
                .getJSONObject("geometry")
                .getJSONObject("viewport")
                .getJSONObject("southwest");

        double latitudeSW  = location.getDouble("lat");
        double longitudeSW = location.getDouble("lng");
        
        location = json.getJSONArray("results")
        		.getJSONObject(0)
        		.getJSONObject("geometry")
        		.getJSONObject("viewport")
        		.getJSONObject("northeast");
        
        double latitudeNE  = location.getDouble("lat");
        double longitudeNE = location.getDouble("lng");
        
        Coordinates viewportSW = new Coordinates(latitudeSW, longitudeSW);
        Coordinates viewportNE = new Coordinates(latitudeNE, longitudeNE);

        Pair<Coordinates, Coordinates> viewport = Pair.of(viewportSW, viewportNE);
        
        return viewport;
    }
    
    /**
     * Get the state that contains a given lon/lat
     * @param coords lon/lat pair to test
     * @return State that contains point or empty string if no state data found in Geocoding API
     * @throws IOException if IO error
     */
    public static String getState(Coordinates coords) throws IOException {
    	String url = "https://maps.googleapis.com/maps/api/geocode/json?address=" +
                UriUtils.encodeFragment(coords.getLatitude() + " " + coords.getLongitude(), "UTF-8") + "&sensor=false&key=" +  Common.GEOCODING_KEY;

        JSONObject json = loadJSON(url); 
        String Status = json.getString("status");
        String state = "";
        if (Status.equalsIgnoreCase("OK")) 
        {
        	JSONArray Results = json.getJSONArray("results");
        	JSONObject zero = Results.getJSONObject(0);
        	JSONArray address_components = zero.getJSONArray("address_components");

        	for (int i = 0; i < address_components.length(); i++) 
        	{
        		JSONObject zero2 = address_components.getJSONObject(i);
        		String long_name = zero2.getString("long_name");
        		JSONArray mtypes = zero2.getJSONArray("types");
        		String Type = mtypes.getString(0);

        		if (Type.equalsIgnoreCase("administrative_area_level_1")) 
        		{
        			state = long_name;
        		} 
        	}
        }
          
        return state;
    }
    
    public static String getZipCode(String address) throws IOException{
    	String url = "https://maps.googleapis.com/maps/api/geocode/json?address=" +
                UriUtils.encodeFragment(address, "UTF-8") + "&sensor=false&key=" + Common.GEOCODING_KEY;

        JSONObject json = loadJSON(url);
        //TODO reformat
        String zip = "";
        JSONArray addressComponents = json.getJSONArray("results").getJSONObject(0).getJSONArray("address_components");
        for(int i = 0; i < addressComponents.length(); i++) {
        	JSONObject element = addressComponents.getJSONObject(i);
        	JSONArray types = element.getJSONArray("types");
        	for(int j = 0; j < types.length(); j++) {
        		String type = types.getString(j);
        		if ("postal_code".equals(type)) {
        			zip = element.getString("long_name");
        			break;
        		}
        	}
        }
        
        return zip;

    }
}
