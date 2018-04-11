uniform highp vec4 u_viewport;
uniform highp vec4 u_lightPosition;
uniform highp float u_lightPower;
uniform highp mat4 u_projectionMatrix;

varying highp vec3 center;
varying highp vec4 v_color;
varying highp float v_radii;
varying highp float k;
void main(void)
{
    vec2 diff = gl_FragCoord.xy - center.xy;
    float d2 = dot(diff,diff);
    float r2 = v_radii*v_radii;
    if (d2 > r2) discard;
    float z = sqrt(r2-d2);
    vec3 norm = normalize(vec3(diff,z));
    gl_FragDepth = center.z+(z-1.)*k/v_radii;
    gl_FragColor = v_color*dot(norm,vec3(0.,0.,1.));
}
/*vec4 result = vec4(0.0, 0.0, 0.0, 0.0);
vec4 eyePosition = vec4(0.0, 0.0, 0.0, 1.0);
vec4 diffMatColor = v_color; //texture2D(u_texture, v_textcoord);
vec3 eyeVect = normalize(vec3(diff,z) - eyePosition.xyz);
vec3 lightVect = normalize(v_position.xyz - u_lightPosition.xyz);
//vec3 reflectLight = normalize(reflect(lightVect, normalize(vec3(diff,z))));
//float len = length(v_position.xyz - eyePosition.xyz);
//float specularFactor = 60.0;
float ambientFactor = 0.20;

vec4 diffColor = diffMatColor * u_lightPower * max(0.0, dot(norm, lightVect));// / (1.0 + 0.25 * pow(len, 2.0));
result += diffColor;
vec4 ambientColor = ambientFactor * diffMatColor;
result += ambientColor;
//vec4 specularColor = vec4(1.0, 1.0, 1.0, 1.0) * u_lightPower * pow(max(0.0, dot(reflectLight, -eyeVect)),specularFactor);// / (1.0 + 0.25 * pow(len, 2.0));
//result += specularColor;*/
