uniform highp vec4 u_lightPosition;
uniform highp float u_lightPower;
varying highp vec4 v_position;
varying highp vec4 v_color;
varying highp vec3 v_normal;

void main(void)
{
    vec4 result = vec4(0.0, 0.0, 0.0, 0.0);
    vec4 eyePosition = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 diffMatColor = v_color; //texture2D(u_texture, v_textcoord);
    vec3 eyeVect = normalize(v_position.xyz - eyePosition.xyz);
    vec3 lightVect = normalize(v_position.xyz - u_lightPosition.xyz);
    vec3 reflectLight = normalize(reflect(lightVect, v_normal));
    float len = length(v_position.xyz - eyePosition.xyz);
    float specularFactor = 60.0;
    float ambientFactor = 0.2;

    vec4 diffColor = diffMatColor * u_lightPower * pow(max(0.0, dot(v_normal, -lightVect)),2.);// / (1.0 + 0.25 * pow(len, 2.0));
    result += diffColor;
    vec4 ambientColor = ambientFactor * diffMatColor;
    result += ambientColor;
    //vec4 specularColor = vec4(1.0, 1.0, 1.0, 1.0) * u_lightPower * pow(max(0.0, dot(reflectLight, -eyeVect)),specularFactor);// / (1.0 + 0.25 * pow(len, 2.0));
    //result += specularColor;
    gl_FragColor = result;
}
