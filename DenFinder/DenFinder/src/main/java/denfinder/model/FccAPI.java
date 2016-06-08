package denfinder.model;

import org.json.JSONObject;

import java.io.IOException;

/**
 * Created by landon on 10/6/14.
 */
public class FccAPI extends ApiCall {
    public static String getFIPSCode(Coordinates coords) throws IOException {

        String url = "http://data.fcc.gov/api/block/find?latitude=" +
                coords.getLatitude() + "&longitude=" + coords.getLongitude() + "&showall=false&format=json";

        //TODO check for status=ok

        JSONObject json = loadJSON(url);

        return json.getJSONObject("Block").getString("FIPS");
    }
}
