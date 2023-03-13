# stlparser
Parses binary STLs into a partial format for a raytracer I have worked on.

## A Pickle for the Knowing Ones
To use this STL parser, your raytracer will need to have a primitive `stltri nx ny nz v1 v2 v3`. It's like `trinormal`, except instead of taking in three normal indices and three vertex indices, it takes a normal and three vertex indices. The normal is the triangle's normal, and the vertices are the triangle's vertices.

The TEST file that is generated sets `eye` to the center of the model, with the z-coordinate set to 2 times the minimum z-coordinate of the entire model minus the maximum z-coordinate of the model, sets `center` to the center of the model, and sets `up` to `{0, 1, 0}`.

In practice, this tends to bring the camera close enough to the model for fine-tuning to be easy.

The only light that the parser sets is an ambient light of `{1, 1, 1}`, so that the model may be identified and fine-tuned more easily.