using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class linescript : MonoBehaviour {
	public int segments;
	private float xradius;
	private float yradius;
	LineRenderer line;
	public GameObject emily;
	public GameObject camera;
	public Transform cam;
	// Use this for initialization
	void Start () {
		line = gameObject.GetComponent<LineRenderer>();

		line.SetVertexCount (segments + 1);
		line.useWorldSpace = false;
		//CreatePoints ();
	}
	void Update(){
		xradius = 6.5f;
		yradius = 3.0f;
		CreatePoints();
	}
	void CreatePoints ()
	{
		float x;
		float z;
		float y = 0f;

		float angle = 20f;

		for (int i = 0; i < (segments + 1); i++)
		{
			x = Mathf.Sin (Mathf.Deg2Rad * angle) * xradius;
			z = Mathf.Cos (Mathf.Deg2Rad * angle) * yradius;
			line.SetPosition (i,new Vector3(x,y,z));

			angle += (360f / segments);

		}
	}




	}

