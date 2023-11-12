/*
modded class SCR_2DOpticsComponent
{
    override static float CalculateZoomFOV(float magnification)
    {
        CameraManager cameraManager = GetGame().GetCameraManager();
        if (!cameraManager)
            return 74;

        float referenceFOV;
        PlayerCamera camera = PlayerCamera.Cast(cameraManager.CurrentCamera());
        if (camera)
            referenceFOV = 28.0;
        else
            referenceFOV = cameraManager.GetFirstPersonFOV();

        float referenceTan = Math.Tan(Math.DEG2RAD * (referenceFOV * 0.5));
        return Math.RAD2DEG * 2 * Math.Atan2(referenceTan, magnification);
    }
}
*/