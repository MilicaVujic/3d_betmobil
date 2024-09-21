# Betmobil Project (3D Expansion)

## Overview

The Betmobil project has been expanded to a 3D environment while retaining the functionality of the previous version. This project now includes a 3D car cockpit, a dynamic 3D scene, and additional features like movement controls, lighting, and environment interactions.

## Features

### 1. **Student Information**
   - The student's name, surname, and my student ID are loaded as a transparent texture and placed in the corner of the screen.

### 2. **3D Cockpit**
   - A 3D cockpit of the Betmobil is created, with the camera positioned at the driver's seat.
   - The instrument panel from the previous project is now rendered in 3D within the car's cockpit.

### 3. **Windshield and External Scene**
   - The windshield is transparent with a slight blue tint, where the upper edge is darker.
   - An external 3D scene is visible through the windshield, which includes a long street with buildings on both sides.

### 4. **Depth Testing and Backface Culling**
   - Depth testing is enabled to ensure proper rendering of objects in 3D space.
   - Backface culling is activated to hide the back faces of objects, improving performance and realism.

### 5. **City Street**
   - The Betmobil drives on a long street with buildings on both sides.
   - The car cannot pass through the buildings, ensuring collision detection.
   - The buildings and the ground have appropriate diffuse and specular maps for realistic lighting and textures.

### 6. **Vehicle Movement**
   - The Betmobil can move forward, backward, and side-to-side (with automatic gear shifting).
   - The car rotates left and right, and movement left or right is half as fast as moving forward or backward.
   - While a key is pressed, the car accelerates (adds gas), and when released, the gas decreases.

### 7. **Camera Perspective**
   - A perspective projection with custom parameters is active.
   - The camera is positioned to show both the instrument panel and the external scene through the windshield.
   - The camera follows the movement of the Betmobil as it drives.

### 8. **Phong Lighting Model**
   - The scene uses the Phong lighting model to calculate realistic lighting effects, including ambient, diffuse, and specular components.

### 9. **Directional Light (Moon)**
   - A directional light simulates moonlight in the scene, casting shadows and illuminating objects accordingly.
   - The color of the sky is set to match a night-time environment.

### 10. **Headlights**
   - The front headlights of the Betmobil are functional and act as spotlights, illuminating the road ahead and beneath the vehicle.

### 11. **Night Vision Mode**
   - Night Vision Goggles mode can be activated, affecting the entire scene, providing a different visual representation.

### 12. **Moon and Bat Signal**
   - The moon is represented as a 2D object with a visible bat signal on it, loaded as a transparent texture.

### 13. **Instrument Panel Lights**
   - All lights on the instrument panel are now small, short-range, and low-intensity point lights.
   - The behavior of these lights and instruments is linked to in-game conditions, such as vehicle speed and environmental factors.

### 14. **Tachometer**
   - The tachometer now represents the current gas/acceleration level of the vehicle.

### 15. **Steering Wheel**
   - A 3D model of a steering wheel is loaded and visible in the cockpit.

## Usage
### Vehicle Movement
- W: Move forward (accelerate).
- S: Move backward (reverse).
- A: Turn/steer left.
- D: Turn/steer right.
- Q -left rotate.
- E -right rotate.
- Release key: Decrease speed (gas lowers when no movement keys are pressed).
### Additional Controls
- P: Toggle transparency of the custom mouse cursor.
- X: Turn on Goggles mode.
- Y: Turn off Goggles mode.
- L: Turn on the battery light
- K: Turn off the battery light
- G: Turn on the engine light
- H: Turn off the engine light
- N: Turn on headlights
- M: Turn off headlights

## Screenshots
-![alt text](<Screenshot 2024-09-20 212602-1.png>)
-![alt text](<Screenshot 2024-09-20 212452-1.png>) 
-![alt text](<Screenshot 2024-09-20 212123-1.png>)

