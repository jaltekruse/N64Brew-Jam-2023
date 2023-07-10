#ifndef H
#define H

    /*********************************
            Sausage64 Structs
    *********************************/

    typedef struct {
        f32 pos[3];
        f32 rot[4];
        f32 scale[3];
    } FrameData;

    typedef struct {
        u32 framenumber;
        FrameData* framedata;
    } KeyFrame;

    typedef struct {
        const char* name;
        u32 keyframecount;
        KeyFrame* keyframes;
    } Animation;

    typedef struct {
        const char* name;
        const u32 is_billboard;
        Gfx* dl;
    } Mesh;

    typedef struct {
        u16 meshcount;
        u16 animcount;
        Mesh* meshes;
        Animation* anims;
    } ModelData;

    typedef struct {
        u8 interpolate;
        u8 loop;
        Animation* curanim;
        u32 curanimlen;
        float animtick;
        u32 curkeyframe;
        Mtx* matrix;
        void (*predraw)(u16);
        void (*postdraw)(u16);
        void (*animcallback)(u16);
        ModelData* mdldata;
    } ModelHelper;
    
    
    /*********************************
           Sausage64 Functions
    *********************************/
    
    /*==============================
        initmodel
        Initialize a model helper struct
        @param The model helper to initialize
        @param The model data 
        @param An array of matrices for each mesh part
    ==============================*/
    
    
    extern void initmodel(ModelHelper* mdl, ModelData* mdldata, Mtx* matrices);
    
    
    /*==============================
        set_camera
        Sets the camera for Sausage64 to use for billboarding
        @param The view matrix
        @param The projection matrix
    ==============================*/
    
    extern void set_camera(Mtx* view, Mtx* projection);
    
    
    /*==============================
        set_anim
        Sets an animation on the model. Does not perform 
        error checking if an invalid animation is given.
        @param The model helper pointer
        @param The ANIMATION_* macro to set
    ==============================*/
    
    extern void set_anim(ModelHelper* mdl, u16 anim);

      /*==============================
        set_anim
        Sets an animation transition to equivalent keyframes in two animations. 
        Does not perform error checking if an invalid animation is given.
        @param The model helper pointer
        @param The ANIMATION_* macro to set
    ==============================*/

    void set_anim_transition(ModelHelper* mdl, u16 anim);
    
    
    /*==============================
    get_currentanim
    Returns the index of the current animation.
    @param The model helper pointer
    @param The ANIMATION_* macro to set
==============================*/

	u32 get_currentanim(ModelHelper* mdl);
    
    /*==============================
        set_animcallback
        Set a function that gets called when an animation finishes
        @param The model helper pointer
        @param The animation end callback function
    ==============================*/
    
    
    extern void set_animcallback(ModelHelper* mdl, void (*animcallback)(u16));
    
    
    /*==============================
        set_predrawfunc
        Set a function that gets called before any mesh is rendered
        @param The model helper pointer
        @param The pre draw function
    ==============================*/
    
    extern void set_predrawfunc(ModelHelper* mdl, void (*predraw)(u16));
    
    
    /*==============================
        set_postdrawfunc
        Set a function that gets called after any mesh is rendered
        @param The model helper pointer
        @param The post draw function
    ==============================*/
    
    extern void set_postdrawfunc(ModelHelper* mdl, void (*postdraw)(u16));
    
    
    /*==============================
        advance_anim
        Advances the animation tick by the given amount
        @param The model helper pointer
        @param The amount to increase the animation tick by
    ==============================*/
    
    extern void advance_anim(ModelHelper* mdl, float tickamount);
    
    
    /*==============================
        drawmodel
        Renders a Sausage64 model
        @param A pointer to a display list pointer
        @param The model helper data
    ==============================*/
    
    extern void drawmodel(Gfx** glistp, ModelHelper* mdl);

#endif
