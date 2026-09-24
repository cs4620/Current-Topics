# 💡New Idea: History of model space animation
- Empire Strikes Back Battle of Hoth for go-motion: https://www.youtube.com/watch?v=J3u3731eGTM
- Rancor for go-motion/deformation animation: https://www.youtube.com/watch?v=hx0tjP_Zx4w
- Abyss for early CGI: https://www.youtube.com/watch?v=XSLQ_94R4sc
- Jurassic Park herd scene: https://www.youtube.com/watch?v=9v_UCB_qwPc

# 💡New Idea: Armature (Rig)
- An armature is a set of bones that control a set of objects


# 💡New Idea: Bone
- A bone is a part of a armature (rig) that controls a set of objects
- If you move a bone, all of its children bones move as well
- If you move a bone's parent, it will move as well
- A bone controls vertices based on the weight assigned to that vertex for the given bone
- You change the weight of a vertex using a process known as weight painting.


## 👩‍💻Activity: Rigging a model
- Create a model of a fish
- Create an armature
- Create bones in the armature that span the object
- Parent the armature to the fish using `automatic weights`
- Use weight painting to fix the influence of the bones on each vertex
