# Repair Mesh Section Mismatch

This is a plugin for **Unreal Engine Editor 4.14+**.

## Description

It repairs static mesh assets that have been imported from FBX with Unreal Engine
in a way that results with a mismatch beween LOD Sections and Material IDs.  
This importation bug has been fixed in 4.15, however already imported assets
remain unchanged.  
The main donwside of
[this bug](https://answers.unrealengine.com/questions/556621/drag-an-drop-material-to-object-id-not-working-any.html)
is that the drag n drop functionnality for Materials to Static Meshes is broken.
(The material is applied to the wrong section of the Mesh.)  
Also, it breaks code that relies on equality between sections and elements.

## Usage

Add this folder to the `Plugins` folder in your project directory.
If the folder doesn't exist, create it alongside `Content`.  
Relauch the editor. A new button should show up on the main toolbar.
If not, check that the plugin is correctly selected in the plugins menu.  

Select in the viewport the Static Meshes Actor you want to repair, the click on the button.  
Info should appear on the debug log.  

Feel free to report bugs and crashes, I'll look into them.  

By design, this plugin takes materials that are defined on Meshes in the map and applies
them to the mesh asset. If this is not what you want, I can change it. Just open an issue. 




*This piece of software was designed internally by [Exoception](http://exoception.com/)
and is availbile under the MIT License.*
