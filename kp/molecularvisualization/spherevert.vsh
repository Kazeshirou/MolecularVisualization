attribute highp vec3 a_position;
attribute highp float a_radii;
attribute highp vec4 a_color;

uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;
uniform highp mat4 u_modelMatrix;
uniform highp vec4 u_viewport;
//uniform highp float u_koeff;

varying highp vec3 center;
varying highp float v_radii;
varying highp vec4 v_color;
varying highp float k;

void main(void)
{
    mat4 pvm = u_projectionMatrix * u_viewMatrix * u_modelMatrix;
    vec4 v_position = pvm * vec4(a_position,1.);
    gl_Position = v_position;


    vec3 wh = vec3(u_viewport.z-u_viewport.x,u_viewport.w-u_viewport.y,1)/2.;
    vec4 p1 = u_projectionMatrix*(u_viewMatrix*u_modelMatrix*vec4(a_position, 1.)+vec4(a_radii,a_radii,a_radii,0));
    p1.xyz = p1.xyz/p1.w*wh+wh;
    center.xyz = v_position.xyz/v_position.w*wh+wh;
    k = p1.z-center.z;
    v_radii = length(p1.xy-center.xy)*0.9; //*u_koeff;
    gl_PointSize = v_radii*2.; // 1000.*v_radii;
    v_color = a_color;
}
